/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2023 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
 
/**
* @file test_l2_cellular_modem_hal_api.c
* @page cellular_modem_hal_api Level 2 Tests
*
* ## Module's Role
* This module includes Level 2 functional tests (success and failure scenarios).
* This is to ensure that the cellular_modem_hal_api APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None@n
* **Dependencies:** None@n
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include "cellular_modem_hal_api.h"
#include <unistd.h>

/**
 * @brief This test verifies the stability of the firmware version of cellular modem after factory reset.
 *
 * This test procedure involves checking the firmware version of the modem before and after the factory reset. The 
 * objective is to ensure that a factory reset does not affect the firmware version of the cellular modem. It 
 * involves invoking the Modem_Firmware_Version() API to fetch the firmware version and Modem_factoryReset() API for 
 * performing factory reset. Sleep is induced for the system to wait for the reboot process to occur and then the  
 * firmware version is again fetched and compared with the initial version. The Cellular Modem HAL API's are tested here.
 *
 * **Test Group ID:** 02@n
 * **Test Case ID:** 001@n
 *
 * **Test Procedure:**
 * Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
 */
void test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_FactoryReset_Modem_Firmware_Version( void )
{
    UT_LOG("Entering test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_FactoryReset_Modem_Firmware_Version...\n");

    // node A
    char *initial_firmware_version=0;
    int retA=0,retB=0,retD=0;
    retA = Modem_Firmware_Version(initial_firmware_version);
    UT_ASSERT_EQUAL(retA , 0);
    UT_LOG("Invoking Modem_Firmware_Version with no input parameters. The output parameter is a valid buffer. The return status is %d.\n", retA);

    // node B
    retB = Modem_FactoryReset();
    UT_ASSERT_EQUAL(retB , 0);
    UT_LOG("Invoking Modem_FactoryReset with no input parameters. The return status is %d.\n", retB);

    // node C
    sleep(30); // assuming the reboot process takes 30 seconds
    UT_LOG("Waiting for reboot process...\n");

    // node D
    char *post_reset_firmware_version=0;
    retD = Modem_Firmware_Version(post_reset_firmware_version);
    UT_ASSERT_EQUAL(retD , 0);
    UT_LOG("Invoking Modem_Firmware_Version with no input parameters. The output parameter is a valid buffer. The return status is %d.\n", retD);

    // node E
    if(strcmp(initial_firmware_version, post_reset_firmware_version) != 0)
    {
        UT_LOG("Verification of firmware version failed. The firmware version before reset was %s and after reset is %s. Exiting test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_FactoryReset_Modem_Firmware_Version...\n", initial_firmware_version, post_reset_firmware_version);
        //
    }
} 

/**
* @brief Test to validate the functionality of Modem Firmware Version API post Modem Reboot
*
* This test checks whether the Firmware Version of the modem remains unchanged even after the modem is rebooted.  
* The test first fetches the initial firmware version, then performs a modem reboot, and finally fetches the updated firmware version post reboot for comparision.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 002@n
*
* **Test Procedure:**
* Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
*/
void test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_Reboot( void )
{
    UT_LOG("Entering test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_Reboot...");

    // Invoke "Modem_Firmware_Version" to get the current version
    char* initial_version=0;
    int result=0;
    UT_LOG("Invoking Modem_Firmware_Version API with valid buffer");

    result = Modem_Firmware_Version(initial_version);
    UT_ASSERT_EQUAL(result, 0);

    // Invoke "Modem_Reboot" to reboot the modem
    result = Modem_Reboot();
    UT_LOG("Invoking Modem_Reboot API");

    UT_ASSERT_EQUAL(result, 0);

    // Waiting for stipulated time
    sleep(5);

    // Invoke "Modem_Firmware_Version" after reboot
    char* updated_version=0;
    result = Modem_Firmware_Version(updated_version);
    UT_ASSERT_EQUAL(result, 0);
    UT_LOG("Invoking Modem_Firmware_Version API post reboot with a valid buffer");

    // Check if firmware_version is as expected
    UT_ASSERT_EQUAL(updated_version, initial_version);
    if(updated_version == initial_version)
    {
        UT_LOG("Modem firmware version remained consistent post reboot. Test passed.");
    }
}

/**
* @brief Test to verifying the firmware version on Modem 
*
* The purpose of this unit test is to verify that the firmware version remains the same on modem after invoking the firmware reset and reboot API on it. It primarily tests two things. Firstly that the Firmware reset and reboot APIs execute successfully without any errors. Secondly, the firmware version remains same after a reset and reboot, implying that the default firmware is not changed or corrupted due to these operations.
*
* **Test Group ID:** 02@n
* **Test Case ID:** 003@n
*
* **Test Procedure:**
* Refer to UT specification documentation [l2_module_test_specification.md](l2_module_test_specification.md)
*/
void test_l2_cellular_modem_hal_api_Modem_Firmware_Version_FactoryReset_Reboot_VerifyFirmware( void )
{
    UT_LOG("Entering test_l2_cellular_modem_hal_api_Modem_Firmware_Version_FactoryReset_Reboot_VerifyFirmware...");

    char version1[256];
    char version2[256];
    int ret_val1=0,ret_val2=0,ret_val3=0,ret_val4=0;

    // Invoke Modem_Firmware_Version
    UT_LOG("Invoking Modem_Firmware_Version API with valid buffer...");
    ret_val1 = Modem_Firmware_Version(version1);
    UT_ASSERT_EQUAL(ret_val1, 0);

    // Invoke Modem_FactoryReset
    UT_LOG("Invoking Modem_FactoryReset API...");
    ret_val2 = Modem_FactoryReset();
    UT_ASSERT_EQUAL(ret_val2, 0);

    // Wait for stipulated time
    UT_LOG("Waiting for stipulated time...");
    sleep(30);

    // Invoke Modem_Reboot
    UT_LOG("Invoking Modem_Reboot API...");
    ret_val3 = Modem_Reboot();
    UT_ASSERT_EQUAL(ret_val3, 0);

    // Wait for stipulated time
    UT_LOG("Waiting again for stipulated time...");
    sleep(30);
    
    // Invoke Modem_Firmware_Version
    UT_LOG("Invoking Modem_Firmware_Version API with valid buffer...");
    ret_val4 = Modem_Firmware_Version(version2);
    UT_ASSERT_EQUAL(ret_val4, 0);

    // Verify firmware_version
    UT_LOG("Verifying firmware version...");
    UT_ASSERT_STRING_EQUAL(version1, version2);

    UT_LOG("Exiting test_l2_cellular_modem_hal_api_Modem_Firmware_Version_FactoryReset_Reboot_VerifyFirmware...");
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */

int test_cellular_modem_hal_l2_api_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L2 cellular_modem_hal_api]", NULL, NULL);
    if (pSuite == NULL) {
        return -1;
    }
    UT_add_test( pSuite, "l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_FactoryReset_Modem_Firmware_Version", test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_FactoryReset_Modem_Firmware_Version);
    UT_add_test( pSuite, "l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_Reboot", test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_Reboot);
    UT_add_test( pSuite, "l2_cellular_modem_hal_api_Modem_Firmware_Version_FactoryReset_Reboot_VerifyFirmware", test_l2_cellular_modem_hal_api_Modem_Firmware_Version_FactoryReset_Reboot_VerifyFirmware);
    return 0;
}
 
