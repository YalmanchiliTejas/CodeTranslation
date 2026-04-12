#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<cassert>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pi acos(-1.0)
#define ll long long
#define mod 1000000007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

const double g=10.0,eps=1e-7;
const int N=1500+10,maxn=500+100,inf=0x3f3f3f;

ll a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    while(1){
        ll maxx=-1e17,id;
        for(int i=0;i<n;i++)
        {
            if(a[i]>maxx)
            {
                maxx=a[i];
                id=i;
            }
        }
        if(maxx<n)break;
        for(int i=0;i<n;i++)
        {
            if(i==id)a[i]%=n;
            else a[i]+=maxx/n;
        }
        ans+=maxx/n;
    }
    cout<<ans<<endl;
    return 0;
}
/*********************
10
1000 193 256 777 0 1 1192 1234567891011 48 425
*********************/
