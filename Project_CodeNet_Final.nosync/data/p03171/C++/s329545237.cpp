#include <bits/stdc++.h>
using namespace std;
#define N 3009
#define INF 1000000009
#define MOD 1000000007
typedef long long int ll;
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf(x) printf("%d",x);
#define pf2(x,y) printf("%d %d\n",x,y);
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z);
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tr(x) cout<<x<< endl;
#define tr2(x,y) cout<<x<<" "<<y<<" " << endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(x,y,z,a) cout<<x<<" "<<y<<" "<<z<<  " " << a << " " << endl;
ll a[N];
ll dp[N][N],s[N][N];
ll fun(int i,int j){
    if(i==j){return a[i];}
    if(i>j || j<i){return -100000000000000;}
    if(dp[i][j]){return dp[i][j];}
    dp[i][j] = max(s[i][j]-fun(i+1,j),s[i][j]-fun(i,j-1));
    return dp[i][j];
}
int main(){ 
    int i,j,n,m,t,k,x,y;
    sd(n);
    for(i=0; i<n; i++){
        cin >> a[i];
    }
    for(i=0; i<n; i++){
        s[i][i]=a[i];
        for(j=i+1; j<n; j++){
            s[i][j]=s[i][j-1]+a[j];
            // tr3(i,j,s[i][j]);
        }
    }
    ll ans=2*fun(0,n-1)-s[0][n-1];
    tr(ans);
}
