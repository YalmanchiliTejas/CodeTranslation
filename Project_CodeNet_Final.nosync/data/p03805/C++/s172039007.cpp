#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i=(a);i<(b); ++i)
#define nfor(i,b,a) for(int i=(b-1);i>=a;--i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define ifile freopen("point1.in", "r", stdin)
#define ofile freopen("point1.out   ", "w", stdout)
#define fast ios_base::sync_with_stdio(0);\
             cin.tie(0);\
             cout.tie(0);
//#define mp make_pair
#define pb push_back
//#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll_min LONG_LONG_MIN
#define ll_max LONG_LONG_MAX
#define _1 first
#define _2 second
#define sqr(a) ((a)*(a))
const ld PI = 3.141592653589793238462643383279;
const ld EPS = 1e-6;
const ll INF = 1e9 + 7;
const ll MOD = INF;
const ll maxn = 2e5+2;
const ll HASH_MODS[] = { 1000000007333,1000000009367, 1000000075747, 1000000158923, 1000000203119 };
//||||||||||||||||||||LOCAL||||||||||||||||||||||||||
int ma[100][100];
int main(){
    int n,m;
    cin>>n>>m;
    forn(i,0,m){
        int a,b;
        cin>>a>>b;
        ma[a][b]=true;
        ma[b][a]=true;
    }
    string s="";
    forn(i,1,n)
        s+='1'+i;
    int ans=0;
    if (ma[1][2]){
        bool t=true;
        forn(i,2,n)
            if (!ma[i][i+1])
                t=false;
        if (t)
            ans++;
    }
    while (next_permutation(s.begin(),s.end())){
       // cout<<s<<"\n";
        if (ma[1][s[0]-'0']){
                bool t=true;
            forn(i,0,n-2){
                //cout<<s[i]-'0'<<" "<<s[i+1]-'0'<<" "<<ma[s[i]-'0'][s[i+1]-'0']<<"\n";
                if (!ma[s[i]-'0'][s[i+1]-'0'])
                    t=false;
            }
            if (t){
                ++ans;
         //       cout<<"ww";
            }
        }

    }
    cout<<ans;
}
