#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll unsigned long long
#define int long long int
#define vi vector <int >
#define vvi vector < vector < int >  >
#define vii vector < pii >
#define vll vector <ll >
#define pii pair <int, int>
#define pdd pair< double, double>
#define piii pair < pii, int > 
#define pll pair<ll, ll >
#define umap unordered_map
#define pb push_back
#define pq priority_queue
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define fore(i,c) for(int i = 1; i <= (int)c; i++)
#define rep(i,b,c) for(int i = (int)b; i < (int)c; i++)
#define double long double
#define a first
#define b second

string s;
int dp[105][5][3], k;

int f(int pos, int n, int lb){

    if(pos == s.length()){
        return (n == k);
    }
    if(n > k){
        return 0;
    }

    if(dp[pos][n][lb] != -1) return dp[pos][n][lb];

    dp[pos][n][lb] = 0;

    int up = 9;
    if(!lb)
        up = s[pos] - '0';

    for(int i = 0; i <= up; i++){
        dp[pos][n][lb] += f(pos + 1, n + (i != 0), lb|(i < up));
    }    

    return dp[pos][n][lb];
}

int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    memset(dp, -1, sizeof dp);
    cin >> s >> k;
    cout << f(0, 0, 0) << endl;

    return 0;
}