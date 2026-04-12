#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

ll dp[3030][3030];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> a(N);
    REP(i,N){
        cin>>a[i];
        dp[i][i]=0;
    }

    for(int len=1;len<=N;len++){
        for(int i=0;i+len<=N;i++){
            int j = i+len;
            if((N-len) % 2 == 0) dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
            else dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
        }
    }
    cout<<dp[0][N]<<endl;
}