/* 
	Author: ankrypt
*/


#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int
#define ff first
#define ss second


ll N, K, A, B, C;
ll arr[100005];
vector<ll> V;
string S;
ll cntA = 0;
ll cntB = 0;

int main() {
	cin >> S;
	for(int i = 0; i < S.size(); i++) {
		if(S[i] == 'A') {
			cntA++;
		}
		else {
			cntB++;
		}
	}
	if(!cntA || !cntB) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}
/*
	Powered by Buggy Plugin
*/
