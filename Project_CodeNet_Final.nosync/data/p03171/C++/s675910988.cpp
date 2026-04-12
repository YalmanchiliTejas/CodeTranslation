#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define forn(i,a,b) for (int i = a; i <= b; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rc(s) return cout<<s,0
#define rcc(s) cout<<s,exit(0)
#define er erase
#define in insert
#define pi pair <int, int>
# define sz(x) (int)((x).size())
#define int long long

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

const ll inf = 0x3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 3e3 + 11;

int dp[N][N],a[N],n,k,x;
//vector<int>v[N];

int32_t main(){
ios_base::sync_with_stdio(0); cin.tie(0); cerr.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }


    for(int i = n; i > 0; i--){
        for(int j = i; j <= n; j++){
            dp[i][j] = (i==j ? a[i] : max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]));
        }
    }

    rc(dp[1][n]);
return 0;
}
