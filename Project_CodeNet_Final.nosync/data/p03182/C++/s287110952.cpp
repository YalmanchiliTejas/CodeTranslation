//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
struct T{
    ll t[524444],a[524444];
    int L,R;
    ll K;
    void add(int k,int l,int r){
        if(L<=l&&R>=r){
            t[k]+=K;
            a[k]+=K;
            return;
        }
        int m=(l+r)>>1,lc=k<<1,rc=lc^1;
        if(L<=m)add(lc,l,m);
        if(R>m)add(rc,m+1,r);
        t[k]=max(t[lc],t[rc])+a[k];
    }
    ll ask(int k,int l,int r){
        if(L<=l&&R>=r) return t[k];
        int m=(l+r)>>1,lc=k<<1,rc=lc^1;
        if(L>m) return ask(rc,m+1,r)+a[k];
        if(R<=m) return ask(lc,l,m)+a[k];
        return max(ask(rc,m+1,r),ask(lc,l,m))+a[k];
    }
    void ADD(int l,int r,ll k){
        if(!k) return;
        L=l,R=r,K=k;
        add(1,1,262144);
    }
    ll ASK(int l,int r){
        L=l,R=r;
        return ask(1,1,262144);
    }
}t;
int n,m,l[200005],r[200005],a[200005];
ll add[200005],dp[200005],ans;
vector<int> v[200005];
int main(){
    scanf("%d%d",&n,&m);
    ++n;
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",l+i,r+i,a+i);
        ++l[i],++r[i];
        add[l[i]]+=a[i],v[r[i]].pb(i);
    }
    for(int i=2;i<=n;++i){
        t.ADD(1,i-1,add[i]);
        dp[i]=t.ASK(1,i-1);
        ans=max(ans,dp[i]);
        t.ADD(i,i,dp[i]);
        for(int j=0;j<v[i].size();++j){
            int k=v[i][j];
            t.ADD(1,l[k]-1,-a[k]);
        }
    }
    printf("%lld\n",ans);
	//system("pause");
	return 0;
}
