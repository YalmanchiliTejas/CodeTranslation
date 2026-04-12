// link here :
#include <bits/stdc++.h>
using namespace std;

#define NAME "rewind"
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len length()

const int maxn = 2e5;
int n;
int a[3000];
ll dp[3000][3000];
ll cal(int l,int r){
    //cout<<l<<" "<<r<<endl;
    if (l==r) return a[l];
    if (dp[l][r]!=0) return dp[l][r];
    return dp[l][r] = max( a[l] - cal(l+1,r) , a[r] - cal(l,r-1)   );
}
int main(){
    //ifstream cin(NAME".inp");
    //ofstream cout(NAME".out");

    cin>>n;
    //show(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<cal(0,n-1);

}
