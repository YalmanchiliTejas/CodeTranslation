#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x;
ll a[55],b[55];

ll dfs(ll N,ll X){
    ll count=0;
    if(N==0) count=1;
    else if(X==1) count+=0;
    else if(X>=2&&X<=a[N-1]+1){
        count+=dfs(N-1,X-1);
    }
    else if(X==a[N-1]+2){
        count+=b[N-1]+1;
    }
    else if(X>=a[N-1]+3&&X<=2*a[N-1]+2){
        count+=b[N-1]+1;
        count+=dfs(N-1,X-a[N-1]-2);
    }
    else if(X==2*a[N-1]+3){
        count += 2*b[N-1]+1;
    }
    return count;
}

int main(){
    cin >> n >> x;
    a[0]=1;
    b[0]=1;
    for(ll i=1;i<=n;i++){
        a[i]=2*a[i-1]+3;
        b[i]=2*b[i-1]+1;
    }
    ll ans=dfs(n,x);
    cout << ans << endl;
    return 0;
}  
