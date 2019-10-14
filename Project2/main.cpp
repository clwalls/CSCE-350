/***************************************************************************
 * Name: Casey Cole
 * Email: coleca@email.sc.edu
 * Date/Time of Completion: 08/28/19 8:30am
 * 
 * Function: Starting point for C++ code.
 * 
 * Input: Program will ask for 5 numbers from the user. 
 * Output: The program will output the sum of those 5 numbers
 * 
 * Additional comments: 
 *                                                                         *
 ***************************************************************************/

#include <cstdlib>
#include <iostream>


using namespace std;


int main (int argc, char **argv)
{
	cout << "Hello World!" << endl; 
	cout << "Give me two numbers: "; 
	int a(0),b(0); 
	cin >> a >> b; 
	
	int sum = a + b;
	
	cout << "The sum of the two numbers is: " << sum << endl;

}
