#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "GPIO.h"

using namespace exploringBB;
using namespace std;
using namespace cgicc;


int main(){
   Cgicc form;                      // the CGI form object
   GPIO button(46);
   button.setDirection(INPUT);
   int val = button.getValue();

   // get the state of the form that was submitted - script calls itself
   bool isStatus = form.queryCheckbox("status");
 
   // generate the form but use states that are set in the submitted form
   cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
   cout << html() << head() << title("HW9-1") << head() << endl;
   cout << body() << h1("CPE 422/522 Reading a Pushbutton as Digital Input") << endl;
   cout << h1("Reading a Pushbutton on gpio46 via a Web Browser") << endl;
   cout << "<form action=\"/cgi-bin/read_button.cgi\" method=\"POST\">\n";
   cout << "<div>";
   cout << "<input type=\"submit\" value=\"Read Button\" />";
   cout << "</div></form>";
   cout << h2("Pushbutton State") << endl;

   // add html based on button input
   if (val == 1) { cout << h3("Button Not Pressed") << endl; }
   else { cout << h3("Button Pressed") << endl; }
 
  
   cout << body() << html();
   return 0;
}
