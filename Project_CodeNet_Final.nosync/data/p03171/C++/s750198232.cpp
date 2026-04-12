#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define all(v) (v).begin(),v.end()
#define fi first
#define se second
const ll inf=(1e18);
ll dp[4000][4000];
int main(){
int n;
cin>>n;
vector<ll> a(n);
for(int i=0;i<n;i++)cin>>a[i];
for(int len=1;len<=n;len++){
    for(int i=0;i+len<=n;i++){
        int j=len+i;//[i,j)
        if((n-len)%2==0){//すでに取られた石の数が偶数個なら先手番
             dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);//i+1=左端からとる、j-1＝右端からとる
        }
        else{
             dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
        }
    }
}
cout<<dp[0][n]<<endl;
}

