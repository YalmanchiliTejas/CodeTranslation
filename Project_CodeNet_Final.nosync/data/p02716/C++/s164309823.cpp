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
const ll MOD=1e9+7;

int n;
ll a[200010];
ll dp[200010][3];
ll flag[200010][3];

ll ddpp(int x,int y){
    if (flag[x][y]){
        return dp[x][y];
    }
    else{
        flag[x][y]=1;
        if (n%2==0){
            if (y==1){
                if (x==1){
                    dp[x][y]=a[1];
                }
                else{
                    dp[x][y]=ddpp(x-2,y)+a[x];
                }
            }
            else{
                if (x==2){
                    dp[x][y]=max(a[1],a[2]);
                }
                else{
                    dp[x][y]=max(ddpp(x-2,y)+a[x],ddpp(x-1,1));
                }
            }
            return dp[x][y];
        }
        else{
            if (y==2){
                if (x==1){
                    dp[x][y]=a[x];
                    return a[x];
                }
                else{
                    dp[x][y]=ddpp(x-2,y)+a[x];
                    return dp[x][y];
                }
            }
            else if (y==1){
                if (x==2){
                    dp[x][y]=max(a[x],a[x-1]);
                    return dp[x][y];
                }
                else{
                    dp[x][y]=max(ddpp(x-2,y)+a[x],ddpp(x-1,y+1));
                    return dp[x][y];
                }
            }
            else{
                if (x==1){
                    dp[x][y]=0;
                    return 0;
                }
                else if (x==3){
                    dp[x][y]=max(a[1],max(a[2],a[3]));
                    return dp[x][y];
                }
                else{
                    dp[x][y]=max(ddpp(x-2,y)+a[x],max(ddpp(x-1,y+1),ddpp(x-2,y+2)));
                    return dp[x][y];
                }
            }
        }
    }
}


int main() {
    cin>>n;
    rep(i,n){
        cin>>a[i+1];
    }
    ddpp(n,0);
    cout<<dp[n][0]<<endl;
    return 0;
}