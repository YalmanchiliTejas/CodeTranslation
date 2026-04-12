#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005
#define INF 1001001001

int main() {
    int n;
    cin >> n;

    ll rmin,rmax,bmin,bmax;
    rmin = INF;
    rmax = 0;
    bmin = INF;
    bmax = 0;
    vector<pair<ll,ll>> v;
    rep(i,n){
        ll a,b; cin >> a >> b;
        if(a>b)swap(a,b);
        v.push_back(P(a,b));
        if(a<rmin)rmin = a;
        if(rmax<a)rmax = a;
        if(b<bmin)bmin = b;
        if(bmax<b)bmax = b;
    }
    ll ans = (rmax-rmin)*(bmax-bmin); // パターン1

    /*
    rep(i,n){
        if(v[i].first==rmin && v[i].second==bmax){
            cout << ans << endl;
            return 0;
        }
    }
    */
    sort(v.begin(),v.end());

    int use[n] = {};
    
    rmax = bmax;
    bmax = 0;
    bmin = INF;
    rep(i,v.size()){
        if(v[i].first==rmin){
            ll b = v[i].second;
            if(b<bmin)bmin = b;
            if(bmax<b)bmax = b;
            use[i] = 1;
        }else if(v[i].second==rmax){
            ll b = v[i].first;
            if(b<bmin)bmin = b;
            if(bmax<b)bmax = b;
            use[i] = 1;
        }else if(v[i].second <= bmax){
            ll b = v[i].second;
            if(b<bmin)bmin = b;
            use[i] = 1;
        }else if(bmin <= v[i].first){
            ll b = v[i].first;
            if(bmax<b)bmax = b;
            use[i] = 1;
        }
    }

    


    rep(i,v.size()){
        if(use[i]==1)continue;
        if(v[i].second<=bmax){ // 決定的
            ll b = v[i].second;
            if(b<bmin)bmin = b;
            continue;
        }
        if(bmin<=v[i].first){ // 終了条件
            bmax = max(bmax,(ll)v[v.size()-1].first);
            ans = min(ans,(rmax-rmin)*(bmax-bmin));
            cout << ans << endl;
            return 0;
        }
        ll tmp_bmin = v[i].first;
        ll tmp_bmax = max(bmax,(ll)v[v.size()-1].first);
        ans = min(ans,(rmax-rmin)*(tmp_bmax-tmp_bmin));
        bmax = max(bmax,(ll)v[i].second);
    }
    ans = min(ans,(rmax-rmin)*(bmax-bmin));

    cout << ans << endl;
    return 0;
}
 
 
