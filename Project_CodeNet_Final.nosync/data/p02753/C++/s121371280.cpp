#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
#include<vector>
#include<algorithm>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
const int maxn = 1e3+5;

int main(){
	string s; cin >> s;
	if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
	else cout << "Yes" << endl;
}