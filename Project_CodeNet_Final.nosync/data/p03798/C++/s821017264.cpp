#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> p(n);
    for(ll i=0;i<(1<<2);i++){ //0はS, 1はW
        p[0]=(i>>0)%2;
        p[1]=(i>>1)%2;
        bool ok=true;
        rep(j,n){
            
            if(j==0){
                if(s[j]=='o'){
                    if(p[j]==0){
                        p[n-1]=p[j+1];
                    }
                    else{
                        p[n-1]=(p[j+1]+1)%2;
                    }
                }
                else{
                    if(p[j]==0){
                        p[n-1]=(p[j+1]+1)%2;
                    }
                    else{
                        p[n-1]=p[j+1];
                    }
                }
            }
            else if(j==n-2){
                if(s[j]=='o'){
                    if(p[j]==0 && p[j+1]!=p[j-1]){
                        ok=false;
                    }
                    else if(p[j]==1 && p[j+1]!=(p[j-1]+1)%2){
                        ok=false;
                    }
                }
                else{
                    if(p[j]==0 && p[j+1]!=(p[j-1]+1)%2){
                        ok=false;
                    }
                    else if(p[j]==1 && p[j+1]!=p[j-1]){
                        ok=false;
                    }
                }
            }
            else if(j==n-1){
                if(s[j]=='o'){
                    if(p[j]==0 && p[0]!=p[j-1]){
                        ok=false;
                    }
                    else if(p[j]==1 && p[0]!=(p[j-1]+1)%2){
                        ok=false;
                    }
                }
                else{
                    if(p[j]==0 && p[0]!=(p[j-1]+1)%2){
                        ok=false;
                    }
                    else if(p[j]==1 && p[0]!=p[j-1]){
                        ok=false;
                    }
                }
            }
            else{
                if(s[j]=='o'){
                    if(p[j]==0){
                        p[j+1]=p[j-1];
                    }
                    else{
                        p[j+1]=(p[j-1]+1)%2;
                    }
                }
                else{
                    if(p[j]==0){
                        p[j+1]=(p[j-1]+1)%2;
                    }
                    else{
                        p[j+1]=p[j-1];
                    }
                }
            }
            
        }
        if(ok){
            rep(j,n){
                if(p[j]==0) cout << 'S';
                else cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}