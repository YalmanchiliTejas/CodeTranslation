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
#define X    first
#define Y    second
//作者:中国江苏南京丁天行
using namespace std;
//数组不要开小了
pair<int,int> p[100005];
pair<int,pair<int,int> >q[200005];
int n,x[100005],y[100005],s,f[100005];
ll ans;
int cty(int x){return x==f[x]?x:f[x]=cty(f[x]);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
    for(int i=1;i<=n;i++)p[i]=mp(x[i],i);
    sort(p+1,p+n+1);
    for(int i=1;i<n;i++)q[++s]=mp(p[i+1].X-p[i].X,mp(p[i].Y,p[i+1].Y));
    for(int i=1;i<=n;i++)p[i]=mp(y[i],i);
    sort(p+1,p+n+1);
    for(int i=1;i<n;i++)q[++s]=mp(p[i+1].X-p[i].X,mp(p[i].Y,p[i+1].Y));
    sort(q+1,q+s+1);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=s;i++){
            if(cty(q[i].Y.X)==cty(q[i].Y.Y)) continue;
            ans+=1ll*q[i].X;
            f[f[q[i].Y.X]]=f[q[i].Y.Y];
    }
    cout<<ans<<endl;
//	system("pause");
	return 0;
}
