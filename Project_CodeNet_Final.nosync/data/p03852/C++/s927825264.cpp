#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cmath>
#include <random>
#include <cctype>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MK make_pair
#define PB push_back
#define VI vector<int>
#define VII vector<int,int>
#define MSI map<string,int>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define W1 while(1);
const int MOD = 1000000007;
int main()
{
	string c;
	cin >> c;
	if (c.at(0) == 'a' || c.at(0) == 'e' || c.at(0) == 'i' || c.at(0) == 'o' || c.at(0) == 'u')
	{
		cout << "vowel" << endl;
	}
	else
	{
		cout << "consonant" << endl;
	}
	return 0;
}