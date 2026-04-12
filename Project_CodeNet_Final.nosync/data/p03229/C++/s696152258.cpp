#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int a[100001];
int main(){
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    sort(a,a+n);
    ll s1=0,s2=0;
    if(n%2==0){
        rep(i,(n-1)/2) s2+=2ll*(a[n-i-1]-a[i]);
        s2+=a[(n-1)/2+1]-a[(n-1)/2];
    }
    else{
        rep(i,(n-2)/2){
            s1+=2ll*(a[n-i-1]-a[i]);
            s2+=2ll*(a[n-i-1]-a[i]);
        }
        s1+=a[(n-2)/2+2]+a[(n-2)/2+1]-a[(n-2)/2]*2;
        s2+=a[(n-2)/2+2]*2-a[(n-2)/2+1]-a[(n-2)/2];
    }
    cout<<max(s1,s2)<<endl;
    return 0;
}