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
//作者:中国江苏南京丁天行
//from CrAzYUnIoN
//I prefer being hacked to being FST
using namespace std;
//数组不要开小了
int n,m;
int ans;
int b[10][10];
int f[300][10];
int cty(int x,int y){
    if(f[x][y]!=-1) return f[x][y];
    if(!(x&(1<<(y-1)))) return f[x][y]=0;
    f[x][y]=0;        
    int X=x;
    x^=(1<<(y-1));
    for(int i=1;i<=n;i++){
            if(!b[i][y]) continue;
            if(!(x&(1<<(i-1)))) continue;
            f[X][y]+=cty(x,i);
    }
    return f[X][y];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
            int q,w;
            scanf("%d%d",&q,&w);
            b[q][w]=b[w][q]=1;
    }
    memset(f,-1,sizeof(f));
    f[1][1]=1;
    for(int i=2;i<=n;i++)f[1<<(i-1)][i]=0;
    for(int i=1;i<=n;i++){
            ans+=cty((1<<n)-1,i);
    }
    printf("%d\n",ans);
	//system("pause");
	return 0;
}
