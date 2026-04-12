#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
    string s;cin>>s;
    int n =s.length();
    int ma;cin>>ma;
    int dp [n+1][ma+1][2];
    rep(i,n+1)rep(j,ma+1)rep(k,2)dp[i][j][k]=0;
    dp[0][0][0]=1;
    rep(i,n)rep(j,4)rep(k,2){
        int nd =s[i]-'0';
        rep(d,10){
            int ni=i+1,nj=j,nk=k;
            if(d!=0)nj++;
            if(nj>ma)continue;
            if(k==0){
                if(nd>d)nk=1;
                if(nd<d)continue;
            }
            dp[ni][nj][nk]+=dp[i][j][k];
        }
    }
    cout<<dp[n][ma][0]+dp[n][ma][1]<<endl;
}