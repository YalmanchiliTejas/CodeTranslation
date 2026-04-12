#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i = 0;i < (n);i++)
#define rep(i,m,n) for(int i = (m);i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
#define Vec(a) vector <int> a
#define F first
#define S second
const int INF = 1 << 20;
const int MOD = 1e9+7;





int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    REP(i,n)
        cin >> a[i];
    sort(a.begin(),a.end());
    ll cnt = 0;
    if(n == 2){
        cout << abs(a[0]-a[1]) << endl;
        return 0;
    }
    int l = 0,r = n-1;
    bool f = true;
    if(n%2){
        ll cnt2 = 0;
        REP(i,n/2){
            cnt -= 2*a[i];
        }
        cnt += a[n/2]+a[n/2+1];
        if((n/2+1) != n-1){
            rep(i,n/2+2,n){
                cnt += 2*a[i];
            }
        }
        sort(a.begin(),a.end(), greater<ll>());
        REP(i,n/2){
            cnt2 += 2*a[i];
        }
        cnt2 -= (a[n/2]+a[n/2+1]);
        if(n/2+1 != n-1){
            rep(i,n/2+2, n){
                cnt2 -= 2*a[i];
            }
        }
        cout << max(cnt, cnt2) << endl;
    }
    else{
        ll cnt2 = 0;
        sort(a.begin(), a.end(), greater<ll>());
        REP(i,n/2-1){
            cnt += 2*a[i];
        }
        cnt += a[n/2-1];
        //cout << cnt << endl;
        cnt -= a[n/2];
        rep(i,n/2+1, n){
            cnt -= 2*a[i];
        }
        
        cout << max(cnt,cnt2) << endl;
    }

    return 0;
}
