#pragma region
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std; 
  
typedef long long LL; 
typedef pair<int, int> pii; 
typedef pair<LL, LL> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<LL> vl; 
typedef vector<vl> vvl; 
typedef map<int,int> mii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
  

double EPS = 1e-9; 
int INF = 1000000005; 
long long INFF = 1000000000000000005LL; 
double PI = acos(-1); 
int mod = 1e9+7;
  
  
#define FOR(a, b, c) for (int(a) = (int)(b); (a) < (int)(c); ++(a)) 
#define FORD(a, b, c) for (int(a) = (int)(b); (a) >= (int)(c); --(a)) 
#define F first 
#define S second 
#define mp make_pair 
#define pb push_back 
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) (int)v.size() 
#define SORT(v) sort(ALL(v)) 
#define SORTC(v, c) sort(ALL(v), c)
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define test(x) int x; cin>>x; while(x--)
#define endl '\n'

void redir()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void showv(const vector<int> &v){for(auto &i:v) cout << i << " "; cout << endl;}
void showv2(const vector<vector<int>> &v1){for(auto &v:v1) showv(v);}
#pragma endregion

//like
int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    redir();

    int n;
    cin >> n;
    
    vl arr(n);
    FOR(i,0,n) cin >> arr[i];

    auto prefix = arr;
    for(int i = n-2; i >= 0; i--)
    {
        prefix[i] = (prefix[i] + prefix[i+1])%mod;
    }

    long long ans = 0;
    FOR(i,0,n-1)
    {
        ans = (ans + (arr[i]*prefix[i+1])%mod)%mod;
    }
    cout << ans << endl;
    return 0; 
} 