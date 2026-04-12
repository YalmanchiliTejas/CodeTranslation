#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    ll N;
    cin >> N;
    vector<ll> eve(N+1/2+1);
    vector<ll> odd(N/2+1);//累積
    vector<ll> eves(N+1/2);
    vector<ll> odds(N/2);
    REP(i,N){
        if(i %2 == 0){
            ll tmp;
            cin >> tmp;
            eve[i/2+1] = eve[i/2]+tmp;
            eves[i/2] = tmp;
        }else{
            ll tmp;
            cin >> tmp;
            odd[i/2+1] = odd[i/2]+tmp;
            odds[i/2] = tmp;
        }
    }
    if(N %2 == 0){
        ll answer = odd[N/2]-odd[0]+eve[0];
        REP(i,N/2+1){
            chmax(answer,odd[N/2]-odd[i]+eve[i]);
        }
        cout << answer << "\n";
    }else{
        ll max0 = 0;
        ll max1 = 0;
        ll max2 = 0;
        REP(i,N/2){
            ll max0b = max0;
            ll max1b = max1;
            ll max2b = max2;
            max0 = max0b+eves[i];
            max1 = max(max1b + odds[i],max0b + odds[i]);
            max2 = max({max0b + eves[i+1],max1b + eves[i+1],max2b + eves[i+1]});
        }
        cout << max({max0,max1,max2}) << "\n";
    }
}