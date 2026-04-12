#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1000000000000000000;

ll dp[110][2][110];

signed main(){
    string s;
    cin>>s;
    ll k;
    cin>>k;
    ll m=s.size();
    V<int> n;
    for(auto a:s) n.push_back(a-'0');
    dp[0][0][0]=1;
    for(int i=0;i<m;i++){
        for(int smaller=0;smaller<2;smaller++){
            for(int j=0;j<=k;j++){
                if(dp[i][smaller][j]==0) continue;
                if(smaller==0){
                    for(int l=0;l<=n[i];l++){
                        if(l==0){
                            if(n[i]!=0) dp[i+1][1][j]+=dp[i][smaller][j];
                            else dp[i+1][0][j]+=dp[i][smaller][j];
                        }else if(l<n[i]) dp[i+1][1][j+1]+=dp[i][smaller][j];
                        else{
                            if(n[i]==0) dp[i+1][0][j]+=dp[i][smaller][j];
                            else dp[i+1][0][j+1]+=dp[i][smaller][j];
                        }
                    }
                }else{
                    for(int l=0;l<=9;l++){
                        if(l) dp[i+1][1][j+1]+=dp[i][smaller][j];
                        else dp[i+1][1][j]+=dp[i][smaller][j];
                    }
                }
            }
        }
    }
    cout<<dp[m][0][k]+dp[m][1][k]<<endl;
}