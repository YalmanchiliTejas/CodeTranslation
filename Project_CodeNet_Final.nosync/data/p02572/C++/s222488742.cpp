#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define ll long long
#define MOD 1000000007

int main(){
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
    #endif

    int n;
    scanf("%d",&n);

    ll a[n];
    ll sum=0;
    
    fo(i,n) cin>>a[i];

    int ar[n];

    ar[0] = a[0];

    for(int i=1; i<n; i++) {
        ar[i] = (ar[i-1] + a[i])%MOD;
    }

    for(int i=0; i<n-1; i++) {
        sum = (sum+(ar[i]*a[i+1])%MOD)%MOD;
    }

    cout<<sum;

    return 0;
}