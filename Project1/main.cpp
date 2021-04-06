/***************************************************************************
 * Name: Christopher Walls
 * Email: clwalls@email.sc.edu
 * Date/Time of Completion: 08/28/19 10:30 PM
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
	int a(0),b(0),c(0),d(0),e(0); 
	int sum = 1;
	cin >> a >> b >> c >> d >> e; 
	do
	{
		sum = a + b + c + d + e;
		cout << sum << endl;
	} while (sum != 0)

}
