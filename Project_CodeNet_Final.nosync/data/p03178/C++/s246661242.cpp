#include <iostream>
using namespace std;

typedef long long ll;
int n,d;
string k;
ll p=1e9+7,dp[10000][100];
ll f(int x, int s, bool b){
    if(x==n){
        if(s%d==0)return 1;
        return 0;
    }
    int y=k[x]-'0',u=9,r=0;
    if(b)u=y;
    else if(dp[x][s]!=-1)return dp[x][s];
    for(int i=0;i<=u;i++){
        r=(r+f(x+1,(s+i)%d,b&&i==u))%p;
    }
    if(!b)dp[x][s]=r;
    return r;
}

int main() {
    cin>>k>>d;
    n=k.length();
    for(int i=0;i<n;i++){
        for(int j=0;j<100;j++){
            dp[i][j]=-1;
        }
    }
    ll ans=(f(0, 0, true)-1+p)%p;
    cout<<ans<<endl;
	return 0;
}
