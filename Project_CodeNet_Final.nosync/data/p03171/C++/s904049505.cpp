#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,arr[3003],mem[3][3005][3005];

ll dp(ll p, ll i1, ll i2){
    if(i1>i2){
        return 0;
    }
    if(mem[p][i1][i2]!=-1)return mem[p][i1][i2];
    if(p==0){
        ll o1=dp(1,i1+1,i2)+arr[i1];
        ll o2=dp(1,i1,i2-1)+arr[i2];
        return mem[p][i1][i2]=max(o1,o2);
    }
    else{
        ll o1=dp(0,i1+1,i2)-arr[i1];
        ll o2=dp(0,i1,i2-1)-arr[i2];
        return mem[p][i1][i2]=min(o1,o2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(ll i=0;i<n;i++)cin>>arr[i];
    memset(mem,-1,sizeof(mem));
    cout<<dp(0,0,n-1);
}