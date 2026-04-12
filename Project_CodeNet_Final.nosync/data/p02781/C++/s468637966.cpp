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
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,1,-1,1,-1,-1,0};
int dy[]={0,1,1,-1,-1,1,0,-1};


LL dp[200][4][2];
int K;
string s;

LL rec(int t,int k, bool f){
    if(k >= 4) return 0;
    if(t == s.length()){
        if(k == K) return 1;
        else return 0;
    }
    if(~dp[t][k][f]) return dp[t][k][f];
    int mx = 9;
    if(f) mx = s[t] - '0';
    LL ret = 0;
    for (int i = 0; i <= mx; i++) {
        ret = ret + rec(t+1,k+(i!=0),f&i==mx);
    }
    return dp[t][k][f] = ret;
}


int main(){
    memset(dp,-1,sizeof(dp));
    cin >> s >> K;
    cout << rec(0,0,1) << endl;
    return 0;
}
