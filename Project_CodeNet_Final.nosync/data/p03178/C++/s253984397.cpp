#include <bits/stdc++.h>
using namespace std;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second

const int maxn=1e4+10,MOD=1e9+7;
int d,f[maxn][101][2];
string k;
vector<int> num;
int calc(int i,int mod,int ok)
{
    //cout<<i<<" "<<mod<<"\n";
    if(i==num.size()) return(mod==0);
    if(f[i][mod][ok]!=-1) return f[i][mod][ok];
    int ret=0;
    int lim=(ok?9:num[i]);

    forinc(dig,0,lim)
    {
        int m=mod,ok1=ok;
        if(ok==0&&dig<lim) ok1=1;
        ret=(ret+calc(i+1,(m+dig)%d,ok1))%MOD;
    }
    return f[i][mod][ok]=ret;
}
main()
{
    cin>>k;
    cin>>d;
    for(auto &v:k) num.push_back(v-'0');
    memset(f,-1,sizeof f);
    int kq=calc(0,0,0);
    cout<<(kq-1+MOD)%MOD;
}
