#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, x; cin>>n>>x;
    vector<ll> cntP(60, 0), l(60, 0);
    cntP[0]=1, l[0]=1;
    for(int i=1; i<=n; i++){
        cntP[i]=cntP[i-1]*2+1;
        l[i]=l[i-1]*2+3;
    }

    ll lb=1, ub=l[n];
    ll ans=0;
    while(n--){ // [lb, ub]
        ll mid=(lb+ub)/2;

        if(x==lb){
            break;
        }
        else if(lb<x && x<mid){
            ub=mid-1;
            lb++;
            if(n==0) ans++;
        }
        else if(x==mid){
            ans+=cntP[n]+1;
            break;
        }
        else if(mid<x && x<ub){
            lb=mid+1;
            ub--;
            ans+=cntP[n]+1;
            if(n==0) ans++;
        }
        else if(x==ub){
            ans+=cntP[n+1];
            break;
        }
    }
    cout << ans << endl;
}