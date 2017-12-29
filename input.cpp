#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

std::string alltel(std::string cellNumber);
std::string att(std::string cellNumber);
std::string boostMobile(std::string cellNumber);
std::string cricketWireless(std::string cellNumber);
std::string metroPCS(std::string cellNumber);
std::string projectFi(std::string cellNumber);
std::string republicWireless(std::string cellNumber);
std::string sprint(std::string cellNumber);
std::string tmobile(std::string cellNumber);
std::string uscellular(std::string cellNumber);
std::string verizonWireless(std::string cellNumber);
std::string virginMobile(std::string cellNumber);

  /* Use std::cerr to write to a different stream, and 
  the bash script will capture std::cout stream.
  Remember to COMPILE this file (g++ input.cpp -o input) 
  before executing the shell script.

  NOTE MMS Texts are not yet supported
  
  Order of which variables are output:
  1. Provider
  2. Number of Texts
  3. Provider Gateway (ex. 1112223333@messaging.sprintpcs.com)
  4. Message to Send

  
    CARRIER | SMS GATEWAY DOMAIN | MMS GATEWAY DOMAIN
    -------- -------------------- -------------------
    Alltel  | sms.alltelwireless.com | mms.alltelwireless.com
    -------- ------------------------ -----------------------
    AT&T    | txt.att.net | mms.att.net
    -------- ------------- ------------
    Boost Mobile | sms.myboostmobile.com | myboostmobile.com
    ------------- ----------------------- ------------------
    Cricket Wireless | sms.mycricket.com | mms.cricketwireless.net
    ----------------- ------------------- ------------------------
    MetroPCS | mymetropcs.com | mymetropcs.com
    --------- ---------------- ---------------
    Project Fi | msg.fi.google.com | msg.fi.google.com
    ----------- ------------------- ------------------
    Republic Wireless | text.republicwireless.com | NULL
    ------------------ --------------------------- ------
    Sprint | messaging.sprintpcs.com | pm.sprint.com
    ------- ------------------------- --------------
    T-Mobile | tmomail.net | tmomail.net
    --------- ------------- ------------
    U.S. Cellular | email.uscc.net | mms.uscc.net
    -------------- ---------------- -------------
    Verizon Wireless | vtext.com | vzwpix.com
    ----------------- ----------- -----------
    Virgin Mobile | vmobl.com | vmpix.com
    -------------- ----------- ----------
   */

  int main () {
    int i = 0; int x = 0;
    bool providerFound = false;
    bool acceptableInput = false;
    std::string providerGateway = "";
    std::string acceptableProviders[12] = {"Alltel", "AT&T", "Boost Mobile", "Cricket Wireless",
					   "MetroPCS", "Project Fi", "Republic Wireless", "Sprint", 
					   "T-Mobile", "U.S. Cellular" ,"Verizon Wireless" ,"Virgin Mobile"};

    std::string acceptableResponse[15] = {"n", "N", "no", "NO", "nO", "No", "y", "Y", "yes", "YES", "yEs", 
					  "yES", "Yes", "yeS", "YEs"};

    /*****************************************************************************/

    std::cerr << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
    std::cerr << "CPP File Start" << std::endl;

    std::cerr << "Enter Service Provider Exactly How it Appears in the List Below: " << std::endl;
    std::cerr <<  "Alltel | AT&T | Boost Mobile | Cricket Wireless" << std::endl;
    std::cerr << "MetroPCS | Project Fi | Republic Wireless | Sprint" << std::endl;
    std::cerr << "T-Mobile | U.S. Cellular | Verizon Wireless | Virgin Mobile" << std::endl;
    std::string provider; std::cin >> provider;

    // Loop through to confirm the provider is acceptable
    while(providerFound==false) {      
      if(acceptableProviders[i]==provider) {
	std::cerr << "Provider Found! Acceptable." << std::endl;
	providerFound = true;
      }
      else if(i >= 11) {
	// Provider not found, exit
	std::cerr << "Provider Not Found, Exiting. Maybe next time you'll get it right." << std::endl;
	std::cerr << "One day I'll let you try more than once without re-running the program." << std::endl;
	std::cerr << "NOTE: If your provider is not in the list, kys." << std::endl;
	std::exit(0);
      }
      else {
	++i;
      }
    }

    /*****************************************************************************/

    std::cerr << "Enter number of texts you would like to send (integer): " << std::endl;
    std::string numTexts; std::cin >> numTexts;
    std::cerr << "Number of Texts Accepted." << std::endl;

    /*****************************************************************************/

    std::cerr << "Enter the number for which you are sending this text: " << std::endl;
    std::string number; std::cin >> number;

    if(number.length() > 10 || number.length() < 10) {
      std::cerr << "Invalid Number, Exiting." << std::endl;
      std::cerr << "Stupid, Number must be in the following format: " << std::endl;
      std::cerr << "111222333" << std::endl;
      std::exit(0);
    }
    std::cerr << "Number Accepted." << std::endl;

    if(provider == "Alltel")
      providerGateway = alltel(number);
    if(provider == "AT&T")
      providerGateway = att(number);
    if(provider == "Boost Mobile")
      providerGateway = boostMobile(number);
    if(provider == "Cricket Wireless")
      providerGateway = cricketWireless(number);
    if(provider == "MetroPCS")
      providerGateway = metroPCS(number);
    if(provider == "Project Fi")
      providerGateway = projectFi(number);
    if(provider == "Republic Wireless")
      providerGateway = republicWireless(number);
    if(provider == "Sprint")
      providerGateway = sprint(number);
    if(provider == "T-Mobile")
      providerGateway = tmobile(number);
    if(provider == "U.S. Cellular")
      providerGateway = uscellular(number);
    if(provider == "Verizon Wireless")
      providerGateway = verizonWireless(number);
    if(provider == "Virgin Mobile")
      providerGateway = virginMobile(number);

    /*****************************************************************************/

    std::cerr << "Enter the message you would like to send: " << std::endl;

    // Discard characters until newline is found 
    // -- without this, this section is skipped and message is blank
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string message; std::getline(std::cin, message);

    if(message.length() > 160) {
      std::cerr << "Message too long. Message Limit is 160 Characters. Exiting." << std::endl;
      std::exit(0);
    }
    std::cerr << "Message Accepted." << std::endl;

    /*****************************************************************************/

    std::cerr << "You entered: " << provider << "; " << numTexts << "; " << number << 
      "; " << message << std::endl;
    std::cerr << "Would you like to proceed? Anything other than no will continue the program." << std::endl;
    std::string response; std::cin >> response;
    
    // Confirm if user would like to proceed
    while(acceptableInput==false) {
      if(acceptableResponse[x]==response) {
	if(x <= 5) {
	  std::cerr << "User Decline. Exiting." << std::endl;
	  std::exit(0);
	}
	else if(x > 5 && x <= 14) {
	  std::cerr << "Acceptable Answer. Proceeding." << std::endl;
	  acceptableInput = true;
	}
      }
      else if(x > 14) {
	std::cerr << "Not an acceptable response. Just say yes or no. Or kys. Yup, we're exiting." << std::endl;
	std::exit(0);
      }
      else
	++x;      
    }

    // Output all variables to std::cout to be captured by script
    std::cerr << std::endl << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
    std::cerr << "COUT STREAM: Captured by script." << std::endl;
    std::cout << provider << std::endl << numTexts << std::endl << providerGateway 
	      << std::endl << message << std::endl;
    std::cerr << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl << std::endl;

    std::cerr << "CPP File Finished." << std::endl;
    std::cerr << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
}

std::string alltel(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@sms.alltelwireless.com";
  return providerDomain;
}
std::string att(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@txt.att.net";
  return providerDomain;
}
std::string boostMobile(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@sms.myboostmobile.com";
  return providerDomain;
}
std::string cricketWireless(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@sms.mycricket.com";
  return providerDomain;
}
std::string metroPCS(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@mymetropcs.com";
  return providerDomain;
}
std::string projectFi(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@msg.fi.google.com";
  return providerDomain;
}
std::string republicWireless(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@text.republicwireless.com";
  return providerDomain;
}
std::string sprint(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@messaging.sprintpcs.com";
  return providerDomain;
}
std::string tmobile(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@tmomail.net";
  return providerDomain;
}
std::string uscellular(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@email.uscc.net";
  return providerDomain;
}
std::string verizonWireless(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@vtext.com";
  return providerDomain;
}
std::string virginMobile(std::string cellNumber) {
  std::string providerDomain = cellNumber + "@vmobl.com";
  return providerDomain;
}
