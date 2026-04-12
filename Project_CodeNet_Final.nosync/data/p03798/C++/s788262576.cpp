#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

const char UNDEF=-1;
signed main() {
    ll N;
    string s;
    cin>>N>>s;

    rep (k,0,4){
        // 羊=1, オオカミ=0
        vector<ll> ans(N, UNDEF);
        switch(k){
            case 0: ans[0]=1; ans[1]=1; break;
            case 1: ans[0]=1; ans[1]=0; break;
            case 2: ans[0]=0; ans[1]=1; break;
            case 3: ans[0]=0; ans[1]=0; break;
        }
        rep(i,2,N){
            if (ans[i-1] && s[i-1]=='o') ans[i] = ans[i-2];
            else if (ans[i-1] && s[i-1]=='x') ans[i] = 1-ans[i-2];
            else if (!ans[i-1] && s[i-1]=='o') ans[i] = 1-ans[i-2];
            else ans[i]=ans[i-2];
        }

        bool valid=true;
        rep(i,0,N){
            if      ( ans[(i+1)%N]  && s[(i+1)%N]=='o' && ans[i] == ans[(i+2)%N]) ;
            else if ( ans[(i+1)%N]  && s[(i+1)%N]=='x' && ans[i] != ans[(i+2)%N]) ;
            else if (!ans[(i+1)%N]  && s[(i+1)%N]=='o' && ans[i] != ans[(i+2)%N]) ;
            else if (!ans[(i+1)%N]  && s[(i+1)%N]=='x' && ans[i] == ans[(i+2)%N]) ;
            else
                valid=false;
        }
        if (!valid)
            continue;
        rep(i,0,N){
            cout<<(ans[i]==1?"S":"W");
        }
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}
