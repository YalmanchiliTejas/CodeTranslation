#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007

ll n,a[200005];
int main(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    if(n%2){
        for(ll i=n;i>=1;i-=2) cout<<a[i]<<" ";
        for(ll i=2;i<n;i+=2) cout<<a[i]<<" ";
    }
    else{
        for(ll i=n;i>=1;i-=2) cout<<a[i]<<" ";
        for(ll i=1;i<n;i+=2) cout<<a[i]<<" ";
    }

}
