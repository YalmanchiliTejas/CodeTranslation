#include <bits/stdc++.h>
#define ll long long
#define all(a) (a).begin(), (a).end()
#define int long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define sz() size()
#define fr first
#define sc second
#define pb push_back
#define er erase
#define in insert
#define mp make_pair
#define rc(s) return cout<<s,0
using namespace std;

int n,a[25];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int maxi=0,ans=0;
    for(int i=1;i<=n;i++){
        maxi=max(maxi,a[i-1]);
        if(a[i]>=maxi) ans++;
    }
    rc(ans);
}
