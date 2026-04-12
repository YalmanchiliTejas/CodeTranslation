#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

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

int n;
ll a[3010];
ll dp[3010][3010];
int flag[3010][3010];

ll ddpp(int x,int y){
    if (flag[x][y]){
        return dp[x][y];
    }
    else{
        flag[x][y]=1;
        if (x==y){
            dp[x][y]=a[x];
            return dp[x][y];
        }
        else{
            dp[x][y]=max(-ddpp(x,y-1)+a[y],-ddpp(x+1,y)+a[x]);
            return dp[x][y];
        }
    }
}


int main() {
    cin>>n;
    rep(i,n){
        cin>>a[i+1];
    }
    ddpp(1,n);
    cout<<dp[1][n]<<endl;
    

    return 0;
}