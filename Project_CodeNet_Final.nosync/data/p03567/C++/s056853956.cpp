#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <stack>
#include <cctype>
#include <map>
using namespace std;
bool PathernMatch(char *sWildcard, char *sString)
{
	char *s = NULL;
	char *p = NULL;
	bool bStarChar = false;
	bool bBreak = false;
	do{
		bBreak = false;
		for (s = sString, p = sWildcard; *s; ++s, ++p){
			switch (*p){
			case '?':
				break;
			case '*':
				bStarChar = true;
				sString = s;
				sWildcard = p;
				if (!*++sWildcard)
					return true;
				bBreak = true;
				break;
			default:
				if (*s != *p){
					if (!bStarChar)
						return false;
					sString++;
					bBreak = true;
				}
				break;
			}
			if (bBreak)
				break;
		}
		if (bBreak == false){
			if (*p == '*')
				++p;
			return (!*p);
		}
	} while (true);
}
bool IsMatch(string sString1, string sString2, bool lpUseWildcard = false){
	if (!lpUseWildcard)
		return sString1 == sString2;
	else{
		return PathernMatch(const_cast<char*>(sString1.c_str()), const_cast<char*>(sString2.c_str()));
	}
}
int main(){
	ios::sync_with_stdio(false);
	string sTest;
	string sMatch("*AC*");
	getline(cin, sTest);
	if (IsMatch(sMatch, sTest, true))
		cout << "Yes\n";
	else
		cout << "No\n";
endapp:
	//system("pause > nul");
	return 0;
}