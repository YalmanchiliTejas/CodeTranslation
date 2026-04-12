#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

string s;
int d;

long long dp[10005][105][2];

long long f(int pos, int rem, int flag) {
    if(dp[pos][rem][flag] != -1) return dp[pos][rem][flag];
    if(pos >= s.length() and rem == 0) return dp[pos][rem][flag] = 1;
    if(pos >= s.length()) return dp[pos][rem][flag] = 0;
    
    long long res = 0;
    if(flag) {
        for(int i = 0; i < s[pos]-'0'; i++) {
            res = (res + f(pos+1, (rem+i)%d, 0))%MOD;
        }
        res = (res + f(pos+1, (rem+(s[pos]-'0'))%d, 1))%MOD;
    }
    else {
        for(int i = 0; i <= 9; i++) {
            res = (res + f(pos+1, (rem+i)%d, 0))%MOD;
        }
    }
    return dp[pos][rem][flag] = res;
}


int main() {
	// your code goes here
	cin >> s;
	cin >> d;
	
	memset(dp, -1, sizeof dp);
	cout << (f(0, 0, 1)+MOD-1)%MOD;
	return 0;
}
