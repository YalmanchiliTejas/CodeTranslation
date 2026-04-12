#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ull,ull> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 505

ull s[MAXN],t[MAXN],u[MAXN],v[MAXN];
ull res[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<n;i++)
        cin >> t[i];
    for(int i=0;i<n;i++)
        cin >> u[i];
    for(int i=0;i<n;i++)
        cin >> v[i];

    for(int i=0;i<n;i++)
        if(!s[i])
            for(int j=0;j<n;j++)
                res[i][j]|=u[i];

    for(int i=0;i<n;i++)
        if(!t[i])
            for(int j=0;j<n;j++)
                res[j][i]|=v[i];

//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//            cout << res[i][j] << ' ';
//        cout << '\n';
//    }

    for(int i=63;i>=0;i--)
    {
        ull x=(1ull<<i);
//        db(x)
        vector<pii> rs,cs;
        for(int i=0;i<n;i++)
            if((u[i]&x)!=0)
                rs.push_back(pii(s[i],i));
        for(int i=0;i<n;i++)
            if((v[i]&x)!=0)
                cs.push_back(pii(t[i],i));
//        cout << rs.size() << ' ' << cs.size() << '\n';
        sort(all(rs));
        sort(all(cs));

        if(!rs.size() && !cs.size())
            continue;
        if(!rs.size())
        {
            vector<int> pos0;
            for(int i=0;i<n;i++)
                if(!s[i])
                    pos0.push_back(i);
            if(!pos0.size())
                break;
            for(int i=0;i<cs.size();i++)
                if(cs[i].first)
                    res[pos0[i%pos0.size()]][cs[i].second]|=x;
            continue;
        }
        if(!cs.size())
        {
            vector<int> pos0;
            for(int i=0;i<n;i++)
                if(!t[i])
                    pos0.push_back(i);
            if(!pos0.size())
                break;
            for(int i=0;i<rs.size();i++)
                if(rs[i].first)
                    res[rs[i].second][pos0[i%pos0.size()]]|=x;
            continue;
        }

//        cout << rs.size() << ' ' << cs.size() << '\n';
//        db(cs[0].second)
        for(auto y : cs)
            res[rs[0].second][y.second]|=x;
        for(auto y : rs)
            res[y.second][cs[0].second]|=x;
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<n;j++)
//                cout << res[i][j] << ' ';
//            cout << '\n';
//        }
    }

    bool ok=1;
    for(int i=0;i<n;i++)
    {
        ull x=-1;
        if(s[i])
            x=0;
        for(int j=0;j<n;j++)
        {
            if(s[i])
                x|=res[i][j];
            else
                x&=res[i][j];
        }
        ok&=(x==u[i]);
    }

    for(int i=0;i<n;i++)
    {
        ull x=-1;
        if(t[i])
            x=0;
        for(int j=0;j<n;j++)
        {
            if(t[i])
                x|=res[j][i];
            else
                x&=res[j][i];
        }
        ok&=(x==v[i]);
    }

    if(!ok)
        db(-1)
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << res[i][j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}
/**
2
0 1
1 0
1 1
1 0
**/
