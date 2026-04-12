//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int n, m;
char s[300000];

ll d[300000][2];

ll u[300000], v[300000];

int main()
{
    int i, j, k, l;
    ll ans=0;
    cin>>n>>m;
    scanf("%s", s);
    m=strlen(s);
    if(s[0] == 'B')
    {
        for(i=0;i<m;i++) s[i]=s[i]=='R'?'B':'R';
    }
    for(i=0;i<m;i++)
    {
        if(s[i] == 'R') s[i]='o';
        else s[i]='x';
    }
    if(count(s, s+m, 'o') == m)
    {
        for(k=0;k<2;k++)
        {
            d[0][k]=1;
            d[0][!k]=0;
            for(i=1;i<n;i++)
            {
                d[i][0]=d[i-1][0]+d[i-1][1];
                d[i][1]=d[i-1][0];
                d[i][0]%=MOD, d[i][1]%=MOD;
            }
            if(k == 0)
            {
                ans+=d[n-1][0]+d[n-1][1];
            }
            else
            {
                ans+=d[n-1][0];
            }
        }
        ans%=MOD;
    }
    else
    {
        if(n%2 == 1)
        {
            return !printf("0\n");
        }
        n/=2;
        int mi=MAX;
        int cur=0;
        int flag=0;
        for(i=0;i<m;i++)
        {
            if(s[i] == 'o') cur++;
            else
            {
                if(cur)
                {
                    if(flag == 0)
                    {
                        if(cur%2 == 0) cur++;
                    }
                    else
                    {
                        if(cur%2 == 0)
                        {
                            cur=0;
                            continue;
                        }
                    }
                    mi=min(mi, cur);
                    flag=1;
                }
                cur=0;
            }
        }
        mi/=2;
        if(mi >= n-1)
        {
            ans=1;
            for(i=0;i<n;i++) ans*=2, ans%=MOD;
            ans--;
            ans+=MOD;
            ans%=MOD;
        }
        else
        {
            u[0]=v[0]=1;
            u[1]=1, v[1]=2;
            for(i=2;i<n;i++)
            {
                int idx=max(-1, i-mi-2);
                u[i]=(v[i-1]-(idx==-1?0:v[idx]))%MOD;
                u[i]+=MOD;
                u[i]%=MOD;
                v[i]=v[i-1]+u[i];
                v[i]%=MOD;
            }
            for(i=n-1;i>=n-1-mi;i--)
            {
                ans+=u[i]*(n-i);
                ans%=MOD;
            }
        }
        ans*=2;
        ans%=MOD;
    }
    ans+=MOD;
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}
//*/