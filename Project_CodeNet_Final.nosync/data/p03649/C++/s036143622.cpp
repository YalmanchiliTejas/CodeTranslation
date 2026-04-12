#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(ll x, vector <ll> a, ll lim){
    for(int i=0;i<a.size();i++){
        a[i]+=x;
    }
    int n=a.size();
    ll req=0;
    for(int i=0;i<a.size();i++){
        req+=max((a[i]-lim+n)/(n+1),0LL);
    }
    if(req>x){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int n;
    cin >> n;
    vector <ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    ll steps = sum-n*n;
    ll ans=0;
    if(steps>0) {
        ll l = -1, r = 1e18;
        while (l + 1 < r) {
            ll mid = (l+r)>>1;
            if(check(steps, a, mid)){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        for(int i=0;i<n;i++){
            a[i]+=steps;
        }
        ll done=0;
        for(int i=0;i<n;i++){
            if(a[i]>r){
                done+=((a[i]-r+n)/(n+1));
                a[i]=a[i]-((a[i]-r+n)/(n+1))*(n+1);
            }
        }
        sort(a.begin(),a.end(),greater<ll>());
        for(ll i=0;i<steps-done;i++){
            a[i]-=n+1;
        }
        ans+=steps;
    }
    while(true){
        bool flag=1;
        for(int i=0;i<n;i++){
            if(a[i]>=n){
                flag=0;
            }
        }
        if(flag){
            break;
        }
        ans++;
        int mx=0;
        for(int i=1;i<n;i++){
            if(a[i]>a[mx]){
                mx=i;
            }
        }
        for(int i=0;i<n;i++){
            if(i==mx){
                a[i]-=n;
            }
            else{
                a[i]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}