#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;



int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    ll ans=0;
    repr(b,k+1,n+1) {
        int s=k,t=n%b;
        int r=b-k+max(0,t-k+1)+(n-t-b)/b*(b-k);
        if (k==0) --r;
        ans+=r;
    }
    cout << ans  << endl;


    return 0;   
}
