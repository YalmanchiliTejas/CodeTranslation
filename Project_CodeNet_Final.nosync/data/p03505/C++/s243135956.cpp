#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n,a,b;
    cin>>n>>a>>b;
    if(a >= n){
        cout << 1 << endl;
        return 0;
    }
    ll sum = a-b;
    if(sum <= 0){
        cout << -1 << endl;
        return 0;
    }
    ll ans = (n-a) / sum;
    n -= ans*sum;
    ans *= 2;
    while(n > 0){
        n -= a;
        ans++;
        if(n <= 0)break;
        n += b;
        ans++;
    }
    cout << ans << endl;
}