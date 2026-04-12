#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

int main() {
    
    int n;
    cin>>n;
    vll a(n);
    ll asum=0,a2=0;
    rep(i,n) {
        cin>>a[i];
        asum+=a[i];
        a2+=a[i]*a[i];
        asum%=1000000007;
        a2%=1000000007;
    }
    asum=(asum*asum)%1000000007;
    ll ans=asum-a2;
    if(ans<0){
        ans+=1000000007;
    }
    if(ans%2==1){
        ans+=1000000007;
    }
    ans/=2;
    cout<<ans<<endl;

}
