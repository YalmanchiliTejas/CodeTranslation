#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pII;
#define pb push_back
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof(x))
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int maxn=1e6+5;
//ll fmod(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%mod;y>>=1;x=x*x%mod;}return res;}
//ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
char s[105][105];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", s[i]);
        }
        for(int i = 0; i < n; i++)
        {
            int have = 0;
            for(int j = 0; j < m; ++j)
            {
                if(s[i][j] == '#')
                {
                    have = 1;
                    break;
                }
            }
            if(!have)
            {
                for(int j = 0; j < m; ++j)
                    s[i][j] = '1';
            }
        }

        for(int i = 0; i < m; i++)
        {
            int have = 0;
            for(int j = 0; j < n; ++j)
            {
                if(s[j][i] == '#')
                {
                    have = 1;
                    break;
                }
            }
            if(!have)
            {
                for(int j = 0; j < n; ++j)
                    s[j][i] = '1';
            }
        }
        for(int i = 0; i < n; ++i)
        {
            int have = 0;
            for(int j = 0; j < m; ++j)
                {
                    if(s[i][j] == '1')continue;
               else
                {
                    cout<<s[i][j];
                    have = 1;
                }
                }
                //cout<<have<<endl;
                if(have)cout<<endl;
        }

    }

}














