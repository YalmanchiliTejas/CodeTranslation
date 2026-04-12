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

// vector< vector<ll>> graph;
// vector<bool> visited;
// vector<ar<ll,2>> dp;

// void bfs(int u){
//     queue<ll> q;
//     q.push(u);
//     visited[u] = 1;
//     while(!q.empty()){
//         int u1 = q.front();
//         q.pop();
//         for(auto i = graph[u1].begin();i!=graph[u1].end();i++){
//             num[*i]--;
//             dist[*i] = max(dist[u1] + 1,dist[*i]);
//             if(!visited[*i] && num[*i] == 0){
//                 visited[*i] = 1;
//                 q.push(*i);
//             }
//         }
//     }
// }

// void dfs(ll u){
//     visited[u] = true;
//     if(graph[u].size() == 0){
//         dp[u][0] = 1;
//         dp[u][1] = 1;
//         return;
//     }

//     dp[u][0] = 1;
//     dp[u][1] = 1;
//     for(auto i = graph[u].begin();i!=graph[u].end();i++){
//         if(!visited[*i]){
//             dfs(*i);
//             dp[u][0] *= (dp[*i][0] + dp[*i][1]);
//             dp[u][0] %= mod;
//             dp[u][1] *= (dp[*i][0]);
//             dp[u][1] %= mod;
//         }
//     }
// }

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

// const ll MAX_N = 1e7 + 1;
vector<ll> spf;

void seive(int n){
    for(int i = 1;i<=n;i++)
        spf[i] = i;
    for(int i = 2;i <= n ;i++){
        for(int j = i*i;j<=n;j+=i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }
}

ll primesum(ll a){
    int curr = spf[a];
    int count = 0;
    ll prod = 1;
    while(a != 1){
        count ++;
        a /= spf[a];
        if(spf[a] != curr){
            prod *= (count + 1);
            count = 0;
            curr = spf[a];
        }
    }
    return prod;
}

// void initialize(int n){
//     for(int i=0;i<n;i++){
//         A[i] = i;
//         size1[i] = 1;
//     }
// }

// int root(int i){
//     while(A[i]!=i){
//         // A[i] = A[A[i]];
//         i = A[i];
//     }
//     return i;
// }

// void dsu_union(int a, int b){
//     int size_a = size1[root(a)];
//     int size_b = size1[root(b)];
//     if(size_a > size_b){
//         size1[a] += size_b;
//         A[root(b)] = root(a);
//     }
//     else{
//         size1[b] += size_a;
//         A[root(a)] = root(b);
//     }
// }

void djikstra(vector<vector<ar<ll,2>>> &graph, vector<ll> &dist, ll s){
    dist[s] = 0;
    priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
    for(ll i=0;i<dist.size();i++){
        pq.push({dist[i],i});
    }
    while(!pq.empty()){
        ar<ll,2> now = pq.top();
        pq.pop();
        if(dist[now[1]] != now[0])
            continue;
        for(ar<ll,2> edge: graph[now[1]]){
            if(dist[edge[0]] > (dist[now[1]] + edge[1])){
                dist[edge[0]] = (dist[now[1]] + edge[1]);
                pq.push({dist[edge[0]],edge[0]});
            }
        }
    }
}

ll nck(ll n, ll k){
    ll ans = 1;
    for(ll i = max(k,n-k)+1;i <=n; i++){
        ans *= i;
        ans %= mod;
    }
    ll div = 1;
    for(ll j = min(k,n-k);j>=1;j--){
        div *= j;
        div %= mod;
    }
    return ans * modInverse(div);
}

bool checkminibox(int i, int j, vector<vector<char>>& board){
        map<char, int> mymap;
        for(int i1 = i; i1 < (i+3); i1++){
            for(int j1 = j; j1 < (j+3); j1++){
                if(board[i1][j1] != '.'){
                    mymap[board[i1][j1]] += 1;
                    if(mymap[board[i1][j1]] >= 2)
                        return 0;
                }
            }
        }
        return 1;
    }
    
bool checkboard(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        map<char, int> mymap;
        for(int j=0; j<9; j++){
            if(board[i][j]!='.'){
                mymap[board[i][j]] += 1;
                if(mymap[board[i][j]] >= 2)
                    return 0;
            }
        }
    }
    for(int i=0;i<9;i++){
        map<char, int> mymap;
        for(int j=0; j<9; j++){
            if(board[j][i]!='.'){
                mymap[board[j][i]] += 1;
                if(mymap[board[j][i]] >= 2)
                    return 0;
            }
        }
    }
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            if(!checkminibox(i,j,board))
                return 0;
        }
    }
    return 1;
}

bool solveSudokurec(vector<vector<char>>& board, int count){
    // bool val = checkboard(board);
    if(count == 0)
        return true;
    bool solved = 0;
    // if(count < 14)
    cout<<count<<"\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] == '.'){
                for(int num=0;num<9;num++){
                    board[i][j] = '1' + num;
                    if(checkboard(board))
                    solved = solveSudokurec(board, count - 1);
                    if(solved)
                        break;
                }
                if(solved)
                    break;
                else{
                    board[i][j] = '.';
                    return 0;
                }
            }
        }
        if(solved)
            break;
    }
    return solved;
}

void solveSudoku(vector<vector<char>>& board) {
    int count = 0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            count += (board[i][j] == '.');
        }
    }
    solveSudokurec(board, count);
} 
  
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
    for(ll z1=0;z1<t;z1++){
        ll n;
        cin>>n;
        if(n >= 30)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
