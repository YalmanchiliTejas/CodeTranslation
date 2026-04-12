#include<bits/stdc++.h>
#define show(x) cout<<#x" = "<<x<<endl;
#define show2(x,y) cout<<#x" = "<<x<<" "<<#y<<" = "<<y<<endl;
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> iipair;
typedef pair<unsigned,unsigned> uupair;
typedef vector<int> vec;
typedef vector<unsigned> uvec;

const unsigned LIMIT=100;

ll dp[LIMIT+1][5][2][2];

unsigned k;
string a,b;

ll call(unsigned pos,ll count,bool f1,bool f2)
{
    if(dp[pos][count][f1][f2] != -1 ) return dp[pos][count][f1][f2];
    if(pos==b.length()) return dp[pos][count][f1][f2]=(count==k);
    if(count > k) return dp[pos][count][f1][f2]=0;
    int digit_min,digit_max;
    digit_max=(f1?9:b[pos]);
    digit_min=(f2?0:a[pos]);
    ll res=0;
    for(int i=digit_min;i<=digit_max;++i)
    {
        unsigned npos=pos+1;
        ll ncount=count+(i!=0);
        bool nf1,nf2;
        nf1=f1;
        nf2=f2;
        if(!f1 && i<b[pos]) nf1=1;
        if(!f2 && i>a[pos]) nf2=1;
        res+=call(npos,ncount,nf1,nf2);
    }
    return dp[pos][count][f1][f2] = res;
}

ll solve()
{
    while(a.length()!=b.length()) a="0"+a;
    for(auto &item : a) item-='0';
    for(auto &item : b) item-='0';
    memset(dp,-1,sizeof(dp));
    return call(0,0,0,0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>b>>k;
    cout<<solve()<<"\n";
}