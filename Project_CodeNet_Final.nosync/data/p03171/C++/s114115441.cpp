// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "L - Deque"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 3e3;
ll dp[maxn][maxn];
int a[maxn];
int n;
ll cal(int l, int r){
    if(dp[l][r]!=LLONG_MIN) return dp[l][r];
    if (l==r) return dp[l][r] = a[l];
    return dp[l][r] = max(a[l]-cal(l+1,r), a[r]-cal(l,r-1) );
}

int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) dp[i][j]=LLONG_MIN;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<cal(0,n-1)<<endl;

}
