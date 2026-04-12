#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
/***********debug tools***********/
template<class T> ostream& operator<<(ostream& os, const pair<T,T>& p){os << "{" << p.first << "," << p.second << "}";return os; }
template<class T> inline void print(pair<T,T> p){cerr << p << endl;}
template<class T> inline void print(vector<T> arr) {cerr << "["; for(int i = 0; i < (int)arr.size(); i++)cerr << arr[i] << (i == (int)arr.size() - 1 ? "]" : ",");cerr << endl;}
template<class T> inline void print(vector<vector<T>> arr) {cerr << "[-------------------" << endl; for(int i = 0; i < (int)arr.size(); i++) { print(arr[i]);} cerr << "-------------------]" << endl;}
/*********************************/


int main()
{
    string s; int D; cin >> s >> D;
    for(auto &i : s)i -= '0';
    int n = s.size();
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(D, vector<ll>(2)));
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < D; j++) {
            for(int k = 0; k < 2; k++) {
                for(int d = 0; d <= (k ? 9 : s[i]); d++) {
                    dp[i + 1][(j + d) % D][k || d < s[i]] += dp[i][j][k];
                    dp[i + 1][(j + d) % D][k || d < s[i]] %= mod;
                }
            }
        }
    }
    cout << ((dp[n][0][0] + dp[n][0][1] - 1) % mod + mod) % mod << endl;
}