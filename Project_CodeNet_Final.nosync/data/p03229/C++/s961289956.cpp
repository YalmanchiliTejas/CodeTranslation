#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, arr[100001], rarr[100001];
ll ans, ans2;

int main(){
    scanf("%lld", &n);
    for(ll i=0; i<n; i++)
        scanf("%lld", &arr[i]);
    sort(arr, arr+n);
    
    if (n%2==1){
        for(ll i=0; i<n/2; i++){
            rarr[2*i] = arr[n-1-i];
            rarr[2*i+1] = arr[i];
        }
        for(ll i=1; i<n-1; i++)
            ans += abs(rarr[i] - rarr[i-1]);
        ll a =  abs(rarr[0] - arr[n/2]);
        ll b =  abs(rarr[n-2] - arr[n/2]);
        ans += a>b?a:b;
    }
    else{
        for(ll i=0; i<=n/2; i++){
            rarr[2*i] = arr[n-1-i];
            rarr[2*i+1] = arr[i];
        }
        for(ll i=1; i<n-1; i++)
            ans += abs(rarr[i] - rarr[i-1]);
        ll a =  abs(rarr[0] - rarr[n-1]);
        ll b =  abs(rarr[n-2] - rarr[n-1]);
        ans += a>b?a:b;
    }

    if (n%2==1){
        for(ll i=0; i<n/2; i++){
            rarr[2*i] = arr[i];
            rarr[2*i+1] = arr[n-1-i];
        }
        for(ll i=1; i<n-1; i++)
            ans2 += abs(rarr[i] - rarr[i-1]);
        ll a =  abs(rarr[0] - arr[n/2]);
        ll b =  abs(rarr[n-2] - arr[n/2]);
        ans2 += a>b?a:b;
    }
    else{
        for(ll i=0; i<=n/2; i++){
            rarr[2*i] = arr[i];
            rarr[2*i+1] = arr[n-1-i];
        }
        for(ll i=1; i<n-1; i++)
            ans2 += abs(rarr[i] - rarr[i-1]);
        ll a =  abs(rarr[0] - rarr[n-1]);
        ll b =  abs(rarr[n-2] - rarr[n-1]);
        ans2 += a>b?a:b;
    }

    printf("%lld", ans>ans2?ans:ans2);
    return 0;
}


