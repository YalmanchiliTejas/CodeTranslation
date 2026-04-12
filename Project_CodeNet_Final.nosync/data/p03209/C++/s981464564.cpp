#include <bits/stdc++.h>

#define pb push_back
#define fst first
#define snd second
#define ALL(s) s.begin(),s.end()
#define fill(a,c) memset(&a, c, sizeof(a))
#define fore(i,x,y) for(ll i=x;i<y;i++)
#define SZ(x) ((int)(x).size())
#define PI 3.1415926535897932384626433832795
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
using namespace std;

const int MAXN = 51;
vector<pair<ll,ll>> v(MAXN);
vector<ll> len(MAXN);

ll solve(int n, ll x){
    ll idx = 0;
    if(x > 1){
        idx++;
        if(idx+len[n-1]<x){
            idx += len[n-1];
            if(idx+1<x){
                idx++;
                if(idx+len[n-1]<=x){
                    return v[n].fst;
                }else{
                    return v[n-1].fst+1+solve(n-1,x-idx);
                }
            }else{
                return v[n-1].fst+1;
            }
        }else if(idx+len[n-1]==x){
            return v[n-1].fst;
        }else{
            return solve(n-1,x-idx);
        }
    }else{
        return 0;
    }
}

int main() {FIN;

    v[0] = {1,0};
    len[0] = 1;
    fore(i,1,51){
        v[i].fst = v[i-1].fst*2+1;
        v[i].snd = v[i-1].snd*2+2;
        len[i] = v[i].fst+v[i].snd;
    }
    int n; ll x; cin>>n>>x;
    cout<<solve(n,x);
    return 0;
}

