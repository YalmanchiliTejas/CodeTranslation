#include <bits/stdc++.h>
#define int long long
#define double long double
#define F first
#define S second
using namespace std;

int mod=1e9+7;
const int mx=3005;
int dp[mx][mx], a[mx];
int n;

int fun(int i, int j){
    if(abs(i-j)<2){
        dp[i][j]=max(a[i],a[j]);
        return dp[i][j];
    }
    if(dp[i][j]){
        return dp[i][j];
    }
    int x=1e15, y=1e15;
    if(i+2<n){
        x= fun(i+2,j);
    }
    if(i+1<n && j-1>=0){
        x= min(x, fun(i+1,j-1));
    }
    if(i+1<n && j-1>=0){
        y=fun(i+1,j-1);
    }
    if(j-2>=0){
        y=min(y, fun(i, j-2));
    }
    dp[i][j]=max(x+a[i], y+a[j]);
    return dp[i][j];
}

int32_t main() {
    int T;
    T=1;
    //cin>>T;
    while(T--){
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        
        int x= fun(0,n-1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        // cout<<x<<endl;
        cout<<x-(sum-x);
        cout<<'\n';
    }
	return 0;
}