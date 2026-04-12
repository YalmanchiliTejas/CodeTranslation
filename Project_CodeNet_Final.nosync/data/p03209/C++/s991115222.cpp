#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x;
ll sum[55],b[55];

ll dfs(int p){
    ll ret = 0;
    if(x==sum[p]){
        x=0;
        return b[p];
    }
    if(sum[p-1] +1 == x){
        ret += b[p-1];
        x = 0;
        return ret;
    }
    if(sum[p-1] == x){
        ret += b[p-1];
        if(p==1) ret--;
        x=0;
        return ret;
    }
    if(sum[p-1]+2 <= x){
        ret += b[p-1]+1;
        x -= sum[p-1]+2;
    }
    else{
        x--;
    }
    if(x==0)return ret;
    ret += dfs(p-1);
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
 
    
    cin>>n>>x;
    sum[0]=1,b[0]=1;
    for(int i=0;i<n;i++){
        sum[i+1] = 2*sum[i] + 3;
        b[i+1] = 2*b[i] + 1;
    }
    cout << dfs(n) << endl;
}