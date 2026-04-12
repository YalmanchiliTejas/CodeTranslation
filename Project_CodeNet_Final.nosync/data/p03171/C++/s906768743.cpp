#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define INF ((1LL<<62)-(1LL<<31))

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

ll dp[3001][3001];
int flag[3001][3001];
ll a[3001];

ll ddpp(int i,int j){
    //区間(i,j)でゲームをしたときの最適戦略
    if (flag[i][j]==1){
        return dp[i][j];
    }
    else{
        flag[i][j]=1;
        if (i==j){
            dp[i][j]=a[i];
            return a[i];
        }
        else{
            dp[i][j]=max(a[i]-ddpp(i+1,j),a[j]-ddpp(i,j-1));
            return dp[i][j];
        }
    }

}

int main() {
    ll n;
    cin>>n;
    //ll a[n+1];
    rep(i,n){
        cin>>a[i+1];
    }
    rep(i,n+1){
        rep(j,n+1){
            flag[i][j]=0;
            dp[i][j]=INF*(-1);
        }
    }
    //ddpp(1,n);
    ll ans=ddpp(1,n);
    /*for (int i=1;i<n+1;i++){
        cout<<a[i]<<endl;
        for (int j=i;j<n+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<ans<<endl;


    return 0;
}