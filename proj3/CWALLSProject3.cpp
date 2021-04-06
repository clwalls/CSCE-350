/***************************************************************************
 * Name: Christopher Walls
 * Email: clwalls@email.sc.edu
 * Date: 12/8/2019
 * Time: 9:14
 * Function: has bruteforce method which does a pen and paper implementation for large
 * integers. also karatsuba which is d&c alg 
 * 
 * Additional comments: 
 *
 * Program Output: 
 * Input requirements and format:
 *                                                                         *
 ***************************************************************************/
#include <bits/stdc++.h>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

// Multiplies str1 and str2, and prints result.
template <typename T>
string to_string(const T value)
{
	stringstream ss;
	ss << value;
	
	return ss.str();
}


/* ***********************************************************************************************
* Pencil and paper algorithm to multiply both numbers. It's basically how you would do it by hand
* multiply, carry remainders, and appending zeros when needed
*
*                               START BRUTEFORCE
**************************************************************************************************/
string bruteforce(string num1, string num2)
{
	int len1 = num1.size();
	int len2 = num2.size();
	int carry = 0;
	
	string product = "";
	
	// first check if either number is 0
	if (len1 == 0 || len2 == 0)	
	return "0";

	// will keep the result number in vector in reverse order
	vector<int> result(len1 + len2, 0);

	// index for position in result
	int i_num1 = 0;
	int i_num2 = 0;

	// Go from right to left in num1 (reverse)
	for (int i = len1-1; i >= 0; i--)
	{
		carry = 0;
		int n1 = num1[i] - '0'; //conversion

		// shift position to left after every multiplication 
		i_num2 = 0;

		// Go from right to left in num2
		for (int j = len2-1; j >= 0; j--)
		{
			int n2 = num2[j] - '0'; //conversion

			// Multiply with num1
			int sum = n1*n2 + result[i_num1 + i_num2] + carry;
			// Carry for next iteration if exists
			carry = sum/10;
			// Store result
			result[i_num1 + i_num2] = sum % 10;

			i_num2++;
		}

		// store carry
		if (carry > 0)
		result[i_num1 + i_num2] = result[i_num1 + i_num2] + carry;

		// shift position to left after evry multiplication
		i_num1++;
	}

	// ignore 0s from the right
	int i = result.size() - 1;
	while (i>=0 && result[i] == 0)
	i--;

	//sanity
	if (i == -1)
	return "0";

	// generate the result string by moving back
	while (i >= 0)
	product = product + to_string(result[i--]);

	return product;
}
/* ***********************************************************************************************
*
*                                      END BRUTEFORCE
*                                 
**************************************************************************************************/

string add(string lhs, string rhs) {
	int length = max(lhs.size(), rhs.size());
	int carry = 0;
	int sum_col; // sum of two digits in the same column
	string result;

	// pad the shorter string with zeros
	while (lhs.size() < length)
	lhs.insert(0,"0");

	while (rhs.size() < length)
	rhs.insert(0,"0");

	// build result string from right to left
	for (int i = length-1; i >= 0; i--) {
		sum_col = (lhs[i]-'0') + (rhs[i]-'0') + carry;
		carry = sum_col/10;
		result.insert(0,to_string(sum_col % 10));
	}

	if (carry)
	result.insert(0,to_string(carry));

	// remove leading zeros
	// http://www.cplusplus.com/reference/string/string/ find abscence of char in string
	return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}

string subtract(string lhs, string rhs) {
	int length = max(lhs.size(), rhs.size());
	int diff;
	string result;

	// * 10^n
	while (lhs.size() < length)
	lhs.insert(0,"0");

	while (rhs.size() < length)
	rhs.insert(0,"0");

	for (int i = length-1; i >= 0; i--) {
		diff = (lhs[i]-'0') - (rhs[i]-'0');
		if (diff >= 0)
		result.insert(0, to_string(diff));
		else {
			// borrow from the previous column
			int j = i - 1;
			while (j >= 0) {
				lhs[j] = ((lhs[j]-'0') - 1) % 10 + '0';
				if (lhs[j] != '9')
				break;
				else
				j--;
			}
			result.insert(0, to_string(diff+10));
		}

	}

	return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}
/* **************************************************************************
*  adapted from https://brilliant.org/wiki/karatsuba-algorithm/ not slides sry ;c
* 
****************************************************************************/

//from lefthand/right hand, divide and conquer stuff
string karatsuba(string lhs, string rhs) {
	int length = max(lhs.size(), rhs.size());

	while (lhs.size() < length)
	lhs.insert(0,"0");

	while (rhs.size() < length)
	rhs.insert(0,"0");

	if (length == 1)
	return to_string((lhs[0]-'0')*(rhs[0]-'0'));

	string lhs0 = lhs.substr(0,length/2);
	string lhs1= lhs.substr(length/2,length-length/2);
	string rhs0 = rhs.substr(0,length/2);
	string rhs1 = rhs.substr(length/2,length-length/2);

	//points of reference
	//a=x sub h y sub h
	string p0 = karatsuba(lhs0,rhs0);
	// d = x sub l y sub l
	string p1 = karatsuba(lhs1,rhs1);
	// e = x sub h + x sub l * y sub h + y sub l 
	string p2 = karatsuba(add(lhs0,lhs1),add(rhs0,rhs1));
	// - a - d
	string p3 = subtract(p2,add(p0,p1));

	for (int i = 0; i < 2*(length-length/2); i++)
	p0.append("0");
	for (int i = 0; i < length-length/2; i++)
	p3.append("0");

	string result = add(add(p0,p1),p3);

	return result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
}
// Driver code
int main()
{
	const char delimiter = '*';
	
	int delimP;
	string inputLine;
	string str1 = "";
	string str2 = "";
	
	cout << "Enter two digit strings separated by a * to be multiplied: " << endl;
	cin >> inputLine;
	
	delimP = inputLine.find(delimiter);
	//parse into str1
	for(int i = 0; i < delimP; ++i) {
		str1 = str1 + inputLine[i];
	}
	//parse into str2
	for(int i = delimP+1; i < inputLine.size(); ++i) {
		str2 = str2 + inputLine[i];
	}
	//Call Bruteforce and Karatsuba methods to multiply strings
	cout << "B: " << bruteforce(str1, str2) << endl;
	cout << "K: " << karatsuba(str1, str2) << endl;
	exit(0);
	return 0;
}