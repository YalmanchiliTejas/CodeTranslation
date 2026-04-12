#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const int INF=1e18;
const int MOD=1e9+7;
const int MAX_N=1e5;
int divup(int x,int y){
    if(x%y==0)return x/y;
    else return x/y+1;
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
typedef pair<int,int>P;

signed main(){
    string s;int k;cin>>s>>k;
    int n=s.size();
    int dpk[n+1][5];
    int dpm[n+1][5];
    REP(i,n+1)REP(j,5)dpk[i][j]=dpm[i][j]=0;
    REPS(i,n){
        int d=s[i-1]-'0';
        if(i==1){
            if(d!=0){
                dpk[1][1]=d-1;
                dpk[1][0]=1;
                dpm[1][1]=1;
            }
            else dpm[1][0]=1;
        }
        else{
            if(d!=0){
                REP(j,4){
                    dpk[i][j+1]=dpk[i-1][j]*9;
                    dpk[i][j]+=dpk[i-1][j]+dpm[i-1][j];
                    dpk[i][j]+=dpm[i-1][j-1]*(d-1);
                    dpm[i][j]=dpm[i-1][j-1];
                }
            }
            else{
                REP(j,4){
                    dpk[i][j+1]=dpk[i-1][j]*9;
                    dpk[i][j]+=dpk[i-1][j];
                    dpm[i][j]=dpm[i-1][j];
                }
            }
        }
    }
    cout<<dpk[n][k]+dpm[n][k];
}