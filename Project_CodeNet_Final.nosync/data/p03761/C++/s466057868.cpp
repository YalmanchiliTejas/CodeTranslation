#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>

using namespace std;


int main()
{
	string str[100],str2[200000],strmemo="";
	long long int n, m, a, b, c, now[200][200] = {};
	const long long int mod = 1000000007;
	cin >>n ;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
		for (int j = 0; j < str[i].length(); j++) {
			now[i][str[i][j]]++;
		}
	}
	for (int j = 'a'; j <= 'z'; j++) {
		long long int ma = 999;
		for (int i = 1; i <= n; i++) {
			ma = min(ma, now[i][j]);
		}
		for (int i = 0; i < ma; i++) {
			cout << (char)j;
		}
	}
}
