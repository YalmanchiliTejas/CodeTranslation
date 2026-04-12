#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;



int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll b[n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    reverse(b,b+n);
    ll res=0;
    ll count=0;
    if(n%2==0){
        for(ll i=0;i<(n-2)/2;i++){
            res+=b[i]*2;
            res-=a[i]*2;
        }
        res+=b[n/2-1];
        res-=b[n/2];
    }
    else{
        for(ll i=0;i<(n-2)/2;i++){
            res+=b[i]*2;
            count-=a[i]*2;
        }
        for(ll i=0;i<(n-1)/2;i++){
            res-=a[i]*2;
            count+=b[i]*2;
        }
        res+=(b[n/2]+b[n/2-1]);
        count-=(b[n/2]+b[n/2+1]);
    }
    cout << max(res,count) << endl;
    return 0;
}  
