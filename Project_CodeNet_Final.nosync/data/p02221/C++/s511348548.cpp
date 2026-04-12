#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};

vector<int> a;
string s;
vector<vector<int>> dp(18,vector<int> (1<<18,-1));
int n;

int dfs(int k,int l,int r){
    if(k == n) return a[l];
    if(~dp[k][l]) return dp[k][l];
    int N = 1 << n;
    int p = 1 << (n - k - 1);
    int L = dfs(k + 1, l, (r - p + N)%N), R = dfs(k + 1, (l + p)%N, r);
    if(R < L) swap(L, R);
    int ret;
    if(s[R - L - 1] == '1'){
        ret = R;
    }
    else{
        ret = L;
    }
    return dp[k][l] = ret;
}




int main(){
    cin >> n;
    int N = 1 << n;
    cin >> s;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n",dfs(0, i, i));
    }
    return 0;
}


