#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF_L = 1e17+7;
const long long INF_I = 1e9+7;
const long long MOD = 1e9+7;
const double EPS = 1e-8;
const double PI=acos(-1);

using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	k--;
	for(int i=0;i<n;i++){
		if(s[i]==s[k])continue;
		s[i]='*';
	}
	cout << s << endl;
	return 0;
}
