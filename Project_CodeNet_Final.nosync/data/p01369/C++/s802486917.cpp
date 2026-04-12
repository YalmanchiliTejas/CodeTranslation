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
#define sint(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(i,v.size())cout<<" "<<v[i];cout<<endl
#define sset(s) cout<<#s<<":";each(i,s)cout <<" "<<i;cout<<endl

using namespace std;


typedef pair<int,int>P;

const int MAX_N = 100005;

int main()
{
    map<char,int> mp;
    mp['q'] = 1,mp['w'] = 1,mp['e'] = 1,mp['r'] = 1,mp['t'] = 1,mp['a'] = 1,mp['s'] = 1,mp['d'] = 1,mp['f'] = 1;
    mp['g'] = 1,mp['z'] = 1,mp['x'] = 1,mp['c'] = 1,mp['v'] = 1,mp['b'] = 1;
    while(1){
        string s;
        cin >> s;
        if(s == "#"){
            break;
        }
        int ans = 0;
        int bf = mp[s[0]];
        rep(i,s.length()-1){
            if(mp[s[i+1]] != bf){
                bf = mp[s[i+1]];
                ans++;
            }
        }
        cout << ans << "\n";
    }
}