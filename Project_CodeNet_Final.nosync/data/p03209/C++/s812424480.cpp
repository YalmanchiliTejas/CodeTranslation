#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define FILL0(x) memset(x,0,sizeof(x))

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll thick[55];
ll pate[55];


ll ans=0;
ll x, N;

ll dfs(int p)
{
    ll ret = 0;
    if(x==thick[p])
    {
        x=0;
        return pate[p];
    }
    if(thick[p-1] +1 == x)  //この+1はp次元のbのせい
    {
        ret += pate[p-1];
        x = 0;
        return ret;
    }
    if(thick[p-1] == x)
    {
        ret += pate[p-1];
        if(p==1)  //x!=1のとき，端はbだが，x==1のとき，端がpになるため 
        {
            ret--;
        }    
        x=0;
        return ret;
    }
    if(thick[p-1]+2 <= x)
    {
        ret += pate[p-1]+1; //+1はp次元の真ん中のp
        x -= thick[p-1]+2;
    }
    else
    {
        x--;
    }
    if(x==0)
    {
        return ret;
    }
    ret += dfs(p-1);

    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    cin >> N >> x;

    thick[0]=pate[0]=1;

    rep(i, 55)
    {
        thick[i+1]=2*thick[i]+3;
        pate[i+1]=2*pate[i]+1;
    }
    cout << dfs(N) << endl;

    return 0;
}

