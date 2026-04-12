#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll  long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

ll dp[3001][3001];
ll mod(ll a){
if(a>=0)
    return a;
else return -a;
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
ll a[n];
for(int i=0;i<n;i++)
    cin>>a[i];
ll x=0;
ll l[n+1];
l[0]=0;
for(int i=0;i<n;i++){
    l[i+1]=l[i]+a[i];
}
for(int i=1;i<=n;i++){
    dp[i][i]=a[i-1];
}
for(int i=2;i<=n;i++){
    for(int j=1;j+i<=n+1;j++){
            int p=j,q=j+i-1;
        ll x=min(dp[p+1][q],dp[p][q-1]);
      dp[p][q]=l[q]-l[p-1]-x;
    }
}

cout<<(2*dp[1][n]-l[n])<<endl;


}
