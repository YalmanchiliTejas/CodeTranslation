//#define frostbyte02
#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define LLFOR(i,a,b) for (ll i=a; i<=b; i++)
#define REP(i,a,b) for (int i=a; i<b; i++)
#define FORD(i,a,b) for (int i=a; i>=b; i--)
#define fi first
#define se second
#define pb push_back
#define fastio {ios_base::sync_with_stdio(false); cin.tie(0);}
#define sqr(x) (x)*(x)
#define sqrmod(x) (((x)%MOD)*((x)%MOD))%MOD

using namespace std;
const int MOD = 1e9+7;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main()                                
{
#ifdef frostbyte02
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif
        fastio
        int n; cin >> n;
        string s; cin >> s;
        int k; cin >> k;
        FOR(i,0,n-1)
        {
                if (s[i]!=s[k-1]) s[i] = '*';
        }
        cout << s;
        return 0;  
}
