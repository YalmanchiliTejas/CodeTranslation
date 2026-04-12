#include <bits/stdc++.h>
using namespace std ;

int main()
{
	//freopen("input.txt","r",stdin);
	string s1,s2,s3 ;
	cin >> s1 >> s2 >> s3 ;
	//cout << s1-'0' <<" " << s2-'0' << s3 -'0' ;
	string s = s2+s3 ;
	int tmp = stoi(s);
	tmp%4 == 0 ? cout << "YES\n" : cout << "NO\n";
	return 0 ;
}