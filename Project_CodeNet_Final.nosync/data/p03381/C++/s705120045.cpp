//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define ll long long
#define vi vector<int>
#define mod 1000000007
#define C 0.5772156649
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define cd complex<double>
#define ull unsigned long long
#define base 1000000000000000000
#define fio ios::sync_with_stdio(false);cin.tie(0)

using namespace std;

const double g=10.0,eps=1e-12;
const int N=200000+10,maxn=200000+10,inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;

int a[N],b[N];
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    int mid=b[(n-2)/2],num=0;
    for(int i=0;i<n;i++)
        if(a[i]==mid)
            num++;
    for(int i=0;i<n;i++)
    {
        if(a[i]>mid)printf("%d\n",mid);
        else printf("%d\n",b[(n-2)/2+1]);
    }
    return 0;
}
/***********************

***********************/
