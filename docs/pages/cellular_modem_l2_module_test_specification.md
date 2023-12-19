### Test 1

|Title|Details|
|--|--|
|Function Name|`test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_FactoryReset_Modem_Firmware_Version`|
|Description|This test verifies the functionality of the Modem Firmware Version check before and after a Modem Factory Reset operation.|
|Test Group|Module : 02|
|Test Case ID|001|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :** 
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Obtain the modem firmware version before factory reset | initial_firmware_version = 0 | 0, the return value for success | Should be successful |
| 02 | Perform a factory reset on the modem | No input parameters | 0, the return value for success | Should be successful |
| 03 | Obtain the modem firmware version after factory reset | post_reset_firmware_version = 0 | 0, the return value for success | Should be successful |
| 04 | Compare the firmware version before and after reset. The versions should be the same indicating a successful reset | comparison of initial_firmware_version, post_reset_firmware_version | Not Applicable | Should be successful |


### Test 2

|Title|Details|
|--|--|
|Function Name|`test_l2_cellular_modem_hal_api_Modem_Firmware_Version_Modem_Reboot`|
|Description|This test validates the Modem firmware consistency post reboot using two APIs, Modem_Firmware_Version followed by Modem_Reboot. The purpose is to ensure the firmware version remains unchanged after a modem reboot.|
|Test Group|Module (L2): 02|
|Test Case ID|002|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :**
None

**User Interaction :**
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure :

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Invoke Modem_Firmware_Version API with initial valid buffer | initial_version=0 | result1=0 after invoking Modem_Firmware_Version(initial_version) | Should be successful |
| 02 | Invoke Modem_Reboot API to reboot the modem | None | result=0 after invoking Modem_Reboot() | Should be successful |
| 03 | Wait for 30 seconds to let the modem reboot | None | Wait Time = 30 seconds | Should be successful |
| 04 | Invoke Modem_Firmware_Version API with updated valid buffer post reboot | updated_version=0 | result2=0 after invoking Modem_Firmware_Version(updated_version) | Should be successful |
| 05 | Verify firmware version remains same post reboot | None | updated_version equals initial_version | Should be successful |

### Test 3

|Title|Details|
|--|--|
|Function Name|`test_l2_cellular_modem_hal_api_Modem_Firmware_Version_FactoryReset_Reboot_VerifyFirmware`|
|Description|Test the functionality of factory resetting, rebooting, and verifying the firmware version of the modem using the Modem_Firmware_Version, Modem_FactoryReset and Modem_Reboot APIs|
|Test Group|Module: 02|
|Test Case ID|003|
|Priority|High|

**Pre-Conditions :**
None

**Dependencies :** 
None

**User Interaction :** 
If user chose to run the test in interactive mode, then the test case has to be selected via console.

#### Test Procedure : 

| Variation / Steps | Description | Test Data | Expected Result | Notes|
| -- | --------- | ---------- | -------------- | ----- |
| 01 | Invoke Modem_Firmware_Version API with valid buffer and store the initial version | initial_version = null string | 0 (success return value) | Should be successful |
| 02 | Invoke Modem_FactoryReset API to reset the modem settings | No input data | 0 (success return value) | Should be successful |
| 03 | Wait for 30 seconds for the factory reset to take effect | No input data | 0 (success return value) | Should be successful |
| 04 | Invoke Modem_Reboot API to restart the modem | No input data | 0 (success return value) | Should be successful |
| 05 | Wait for 30 seconds for the reboot to take effect | No input data | 0 (success return value) | Should be successful |
| 06 | Invoke Modem_Firmware_Version API with valid buffer to get the updated version | updated_version = null string | 0 (success return value) | Should be successful |
| 07 | Verify that the initial version equals the updated version after the factory reset and reboot | initial_version = updated_version | True (Both versions are same) | Should be successful |

