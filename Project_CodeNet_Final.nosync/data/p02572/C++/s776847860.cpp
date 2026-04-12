#include<iostream>
#include<numeric>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
#include<utility>
#include<cmath>
#include<tuple>
#include<string>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=b[i-1]+a[i];
    } 
    ll ans=0;
    for(int i=0;i<n-1;i++){
        ll sum=b[n-1]-b[i];
        sum%=1000000007;
        ans+=a[i]*sum;
        ans%=1000000007;
    }
    cout<<ans<<endl;
}