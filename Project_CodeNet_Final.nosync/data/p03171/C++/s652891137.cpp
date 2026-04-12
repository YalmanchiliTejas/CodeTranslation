// Gaurav Nuti
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii > vii;
typedef vector<pll > vll;
#define pb push_back
#define mp make_pair 
#define ar array
#define mod 1000000007
#define F first
#define S second
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define For(i, a, b) for(__typeof (a) i=a; i<=b; i++)
#define inp_arr(a,n) for(__typeof (n) i=0; i<n; ++i) {cin>>a[i];}
#define debug_arr(a,n) {{for(__typeof (n) i=0; i<n; ++i) {cout<<a[i]<<" ";}cout<<"\n";}}
#define INF 1e9 

ll power(ll x, ll y) 
{ 
    ll res = 1;   
    while (y > 0) { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1;
        x = (x*x)%mod; 
    } 
    return res%mod; 
}

ll power_without_mod(ll x, ll y) 
{ 
    ll res = 1;   
    while (y > 0) { 
        if (y & 1) 
            res = (res*x); 
        y = y>>1;
        x = (x*x); 
    } 
    return res; 
}

bool comparep(pair<ll, ll> i1, pair<ll, ll> i2){
	return (i1.S < i2.S);
} 

ll modInverse(ll a)
{
    return power(a , mod - 2);
}

vector< vector<ll>> graph;
vector<ll> num;
vector<bool> visited;
vector<ll> dist;

void bfs(int u){
    queue<ll> q;
    q.push(u);
    visited[u] = 1;
    while(!q.empty()){
        int u1 = q.front();
        q.pop();
        for(auto i = graph[u1].begin();i!=graph[u1].end();i++){
            num[*i]--;
            dist[*i] = max(dist[u1] + 1,dist[*i]);
            if(!visited[*i] && num[*i] == 0){
                visited[*i] = 1;
                q.push(*i);
            }
        }
    }
}

// int next_lunlun(ll n){
//     vector<int> digits;
//     while(n){
//         digits.pb(n%10);
//         n /= 10;
//     }
//     // reverse(digits.begin(),digits.end());
//     ll num_digits = digits.size(); 
//     int count_9 = 0;
//     for(int i: digits)
//         if(i == 9)
//             count_9++;
//     if(count_9 == num_digits)
//         return ;
//     for(int i=0;i<(num_digits-1);i++){
//         if(digits)
//     }
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif  
	
    ll t;
    // cin>>t;
    t = 1;
    for(ll z=0;z<t;z++){
        ll n;
        cin>>n;
        ll a[n];
        inp_arr(a,n);
        ar<ll,2> dp[n][n];
        for(ll k = 0; k < n;k ++){
            for(ll i = 0;i<n;i++){
                ll j = i+k;
                if(j < n){
                    if(k == 0){
                        dp[i][j][0] = a[i];
                        dp[i][j][1] = 0;
                    }
                    else{
                        dp[i][j][0] = max(a[i] + dp[i+1][j][1],
                            a[j] + dp[i][j-1][1]);
                        if(dp[i][j][0] == a[i] + dp[i+1][j][1])
                            dp[i][j][1] = dp[i+1][j][0];
                        else
                            dp[i][j][1] = dp[i][j-1][0];
                    } 
                }
            }
        }
        cout<<dp[0][n-1][0] - dp[0][n-1][1];
    }
}