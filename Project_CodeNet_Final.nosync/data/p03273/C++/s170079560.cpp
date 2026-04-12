#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int h,w;
    cin >> h >> w;
    vector<string> s;
    rep(i,h)
    {
        string a;
        cin >>a;
        bool ok=true;
        rep(k,a.length())
        {
            if(a[k]=='#')
            {
                ok = false;
                break;
            }
        }
        if(!ok) s.push_back(a);
    }
    vector<bool> p(w);
    rep(i,w)p[i]=true;

    rep(i,w)
    {
        bool ok=true;
        rep(k,s.size())
        {
            if(s[k][i]=='#')
            {
                ok=false;
                break;
            }
        }
        if(ok) p[i]=false;
    }

    rep(i,s.size())
    {
        rep(k,w)
        {
            if(p[k])cout<<s[i][k];
        }
        cout<<endl;
    }

    return 0;
}