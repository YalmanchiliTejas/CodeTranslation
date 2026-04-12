#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e4 + 100;
const int mod = (int)1e9 + 7;
const long long INF = (long long)1e18;
int dd;
long long d[N][100];
long long get(string s){
    int n = s.size();
    for(int i = 0;i < 10;i++)d[1][(i % dd)]++;
    for(int i = 2;i <= n;i++){
        for(int m = 0;m < dd;m++){
            for(int j = 0;j < 10;j++){
                d[i][m] += d[i - 1][(((m - j) % dd) + dd) % dd];
                d[i][m] %= mod;
            }
        }
    }
    long long ans = 0;
    int ss = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < (s[i] - '0');j++){
             ss += j;
            if((i == n - 1) && ((ss % dd) == 0))ans++;
            ans += d[n - i - 1][(((dd - ss) % dd) + dd) % dd];
            ans %= mod;
            ss-=j;
        }
        ss += (s[i] - '0');
        if((i == n - 1) && ((ss % dd) == 0))ans++;
    }
    return (ans - 1 + mod) % mod;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    string s;
    cin >> s >> dd;
    cout << get(s);
    return 0;
}