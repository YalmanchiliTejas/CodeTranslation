#include <bits/stdc++.h>
#define pb push_back
#define f first
#define sc second
using namespace std;
typedef long long int ll;
typedef string str;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x, m;
    cin >> n >> x >> m;
    vector <bool> bl(m, 0);
    bl[x] = 1;
    vector <int> seq;
    seq.pb(x);
    ll vl = -1;
    while(1){
        x*=x;
        x%=m;
        if(!bl[x]){
            bl[x] = 1;
            seq.pb(x);
        }
        else{
            vl = x;
            break;
        }
    }
    ll ans = 0;
    while(seq[0] != vl && n > 0){
        ans+=seq[0];
        seq.erase(seq.begin());
        n--;
    }
    ll s = n/seq.size();
    ll sum = 0;
    ll md = n%(seq.size());
    for(auto a: seq) sum+=a;
    ans += sum*s;
    for(int i = 0; i < md; i++) ans+=seq[i];
    cout << ans << "\n";
}
