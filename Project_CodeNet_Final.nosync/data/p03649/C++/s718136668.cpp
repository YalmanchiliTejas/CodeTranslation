#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a, b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define show(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout <<" "<<kbrni;cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

int main()
{
    ll n;
    cin >> n;
    vector<ll> vec(n);
    rep(i,n){
        cin >> vec[i];
    }
    sort(all(vec));
    ll ans = 0;
    while(1){
        if(vec[n-1] <= n-1){
            break;
        }
        bool flag = false;
        rep(i,n-1){
            ll diff = vec[i+1] - vec[i];
            ll hoge = diff / (n+1);
            if(hoge >= 1){
                flag = true;
                for(int j=0;j<=i;j++){
                    vec[j] += hoge*(n-i-1);
                }
                for(int j=i+1;j<n;j++){
                    vec[j] -= hoge*(i+2);
                }
                ans += hoge*(n-i-1);
            }
        }
        if(!flag){
            if(vec[n-1]-(100*n) > 0){
                ans += n*(vec[n-1]-(100*n));
                rep(j,n){
                    vec[j] -= vec[n-1]-(100*n);
                }
            }
            while(vec[n-1] > n-1){
                rep(j,n-1){
                    vec[j]++;
                }
                vec[n-1] -= n;
                ans++;
                sort(all(vec));
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
