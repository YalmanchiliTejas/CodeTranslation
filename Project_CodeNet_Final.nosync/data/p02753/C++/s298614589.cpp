/*
	Copyright: razouq (c)
	Author: Anass BENDARSI
	Date: 07-Mar-20 1:02:05 PM
	flamers will **** you
*/
//#include<flamers.h>

#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define ll long long
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define POB pop_back

using namespace std;

int main(){
//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	string s;
	cin>>s;
	int a = 0, b = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'A') a++;
		else b++;
	}
	if(a == 3 || b == 3) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
