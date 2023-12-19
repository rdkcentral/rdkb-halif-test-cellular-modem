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
* @file test_cellular_modem_hal_api.c
* @page cellular_modem_hal_api Level 1 Tests
*
* ## Module's Role
* This module includes Level 1 functional tests (success and failure scenarios).
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

/**
 * @brief Verify the functionality of Modem_FactoryReset with no input parameters.
 *
 * This test case verifies the functionality of Modem_FactoryReset by invoking it with no input parameters and checking the return value.
 *
 * **Test Group ID:** Basic: 01 @n
 * **Test Case ID:** 001 @n
 * **Priority:** High @n@n
 *
 * **Pre-Conditions:** None @n
 * **Dependencies:** None @n
 * **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console. @n
 *
 * **Test Procedure:** @n
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :--------------: | :-----------: | :---------: | :---------------: | :-----: |
 * |      01          | Invoke Modem_FactoryReset with no input parameters | None | STATUS_SUCCESS | Should be successful |
 */
void test_l1_cellular_modem_hal_api_positive1_Modem_FactoryReset(void) {
    UT_LOG("test_l1_cellular_modem_hal_api_positive1_Modem_FactoryReset...");
    UT_LOG("Invoking Modem_FactoryReset with no input parameters...");
    // Invoke Modem_FactoryReset
    int result = Modem_FactoryReset();
    UT_LOG("Expected Result: STATUS_SUCCESS");
    // Check the return value
    UT_LOG("Return Status: %d", result);
    UT_ASSERT_EQUAL(result, STATUS_SUCCESS);
    UT_LOG("Exiting test_l1_cellular_modem_hal_api_positive1_Modem_FactoryReset...");
}

/**
* @brief Test the Modem_Reboot function for basic reboot functionality
*
* This test case verifies the basic functionality of the Modem_Reboot function.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 002 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: | :--------------: | :-----: |
* | 01 | Invoking Modem_Reboot with no input parameters |None| STATUS_SUCCESS | Should be successful |
*/
void test_l1_cellular_modem_hal_api_positive1_Modem_Reboot(void) {
    // Log entering the test function
    UT_LOG("Entering test_l1_cellular_modem_hal_api_positive1_Modem_Reboot...");
    UT_LOG("Invoking Modem_Reboot with no input parameters.");
    // Perform the test
    int result = Modem_Reboot();
    UT_LOG("Return Status: %d", result);
    UT_LOG("Expected Result: STATUS_SUCCESS");
    // Check the result
    UT_ASSERT_EQUAL(result, STATUS_SUCCESS);
    // Log exiting the test function
    UT_LOG("Exiting test_l1_cellular_modem_hal_api_positive1_Modem_Reboot...");
}

/**
* @brief Test the Modem_Firmware_Version function to ensure it returns the correct firmware version.
*
* This test validates the functionality of the Modem_Firmware_Version API by invoking it with a valid buffer
* and verifying the return value and buffer content.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 003 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke Modem_Firmware_Version with valid buffer | buffer = valid value | STATUS_SUCCESS | Should be successful |
*/
void test_l1_cellular_modem_hal_api_positive1_Modem_Firmware_Version(void) {
    UT_LOG("Entering test_l1_cellular_modem_hal_api_positive1_Modem_Firmware_Version...");
    UT_LOG("Invoking Modem_Firmware_Version with valid buffer...");
    char buffer[128]={0};
    // Invoke Modem_Firmware_Version with valid buffer
    int result = Modem_Firmware_Version(buffer);
    UT_LOG("Expected Result: STATUS_SUCCESS");
    UT_LOG("Return Status: %d", result);
    // Check the return value and buffer content
    UT_ASSERT_EQUAL(result, STATUS_SUCCESS);
    if (strcmp(buffer,"EM06ALAR04A01M4G_01.003.01.003"))
    {
        UT_LOG("Modem_firmware version is returning successfully:%s",buffer);
	    UT_PASS("Modem_firmware version is returning sucess\n");
    }
    else
    {
        UT_LOG("Modem_firmware version is returning failure:%s",buffer);
	    UT_PASS("Modem_firmware version is returning failure\n");
    }
    UT_LOG("Exiting test_l1_cellular_modem_hal_api_positive1_Modem_Firmware_Version...");
}

/**
* @brief Testing the function Modem_Firmware_Version with null pointer for buffer
*
* This test case checks the behavior of the Modem_Firmware_Version function when a null pointer is passed as the buffer argument.
*
* **Test Group ID:** Basic: 01 @n
* **Test Case ID:** 004 @n
* **Priority:** High @n@n
*
* **Pre-Conditions:** None @n
* **Dependencies:** None @n
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console. @n
*
* **Test Procedure:** @n
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | :---------: | :----------: |:--------------: | :-----: |
* | 01 | Invoke Modem_Firmware_Version with null pointer for buffer | buffer = NULL | STATUS_FAILED | Should Fail |
*/
void test_l1_cellular_modem_hal_api_negative1_Modem_Firmware_Version(void) {
    UT_LOG("Entering test_l1_cellular_modem_hal_api_negative1_Modem_Firmware_Version...");
    UT_LOG("Invoking Modem_Firmware_Version with null pointer for buffer...");
    // Invoke Modem_Firmware_Version with null pointer for buffer
    int result = Modem_Firmware_Version(NULL);
    UT_LOG("Expected Result: STATUS_FAILED");
    UT_LOG("Actual Result: %d", result);
    // Check the return value
    UT_ASSERT_EQUAL(result, STATUS_FAILED);
    UT_LOG("Exiting test_l1_cellular_modem_hal_api_negative1_Modem_Firmware_Version...");
}

static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_cellular_modem_hal_l1_api_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1 cellular_modem_hal_api]", NULL, NULL);
    if (pSuite == NULL) {
        return -1;
    }
    UT_add_test( pSuite, "l1_cellular_modem_hal_api_positive1_Modem_FactoryReset", test_l1_cellular_modem_hal_api_positive1_Modem_FactoryReset);
    UT_add_test( pSuite, "l1_cellular_modem_hal_api_positive1_Modem_Reboot", test_l1_cellular_modem_hal_api_positive1_Modem_Reboot);
    UT_add_test( pSuite, "l1_cellular_modem_hal_api_positive1_Modem_Firmware_Version", test_l1_cellular_modem_hal_api_positive1_Modem_Firmware_Version);
    UT_add_test( pSuite, "l1_cellular_modem_hal_api_negative1_Modem_Firmware_Version", test_l1_cellular_modem_hal_api_negative1_Modem_Firmware_Version);
    return 0;
}
