#include <bits/stdc++.h>
    
using namespace std;
    
#define endl "\n"
#define ll unsigned long long
#define int long long int
#define pii pair <int, int>
#define pdd pair< double, double>
#define piii pair < pii, int > 
#define pll pair<ll, ll >
#define vi vector <int >
#define vvi vector < vi > 
#define vii vector < pii >
#define viii vector < piii >
#define vll vector <ll >
#define vb vector <bool > 
#define umap unordered_map
#define pb push_back
#define pq priority_queue
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define rep(i,b,c) for(int i = (int)b; i < (int)c; i++)
#define double long double
#define a first
#define b second

int dp[3005][3005];
vi arr(3005);
const int inf = -1e16;

int f(int i, int j){
    if(i == j){
        return arr[i];
    }

    if(dp[i][j] != inf) return dp[i][j];

    return dp[i][j] = max(arr[i] - f(i + 1, j), arr[j] - f(i, j - 1));

}

int32_t main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    int n;
    cin >> n;
    forn(i, n){
        cin >> arr[i];
    }
    forn(i, 3003){
        forn(j, 3003){
            dp[i][j] = inf;
        }
    }
    cout << f(0, n - 1) << endl;

    return 0;
}
