#include <bits/stdc++.h>
# define ll int64_t
#define rep(i,n) for(ll i=0;i<n;i++)
#define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007

using namespace std;

bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<string,ll> a,pair<string,ll> b){
    
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

int main(){
    ll h,w,counth=0,countw=0;
    cin>>h>>w;
    vector<string> a(h);
    rep(i,h) cin>>a[i];
    rep(i,h) {
        ll c=0;
        rep(j,w){
        if(a[i].at(j)=='.') c++;
        }
        if(c==w) {
            countw++;
            rep(j,w) a[i].at(j)='a';
        }
    }
    rep(i,w){
        ll c=0;
        rep(j,h){
            if(a[j].at(i)=='.' || a[j].at(i)=='a') c++;
        }
        if (c==h){
            counth++;
            rep(j,h) a[j].at(i)='a';
        }
    }
    
    rep(i,h){
        ll d=0;
        rep(j,w){
            if(a[i].at(j)!='a') {
                d++;
                if(d==w-counth) cout<<a[i].at(j)<<endl;
                else cout<<a[i].at(j);
            }
        }
    }
    return 0;
}
