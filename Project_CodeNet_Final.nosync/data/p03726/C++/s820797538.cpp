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
int n,cnt[100005],c[100005];
queue<int> q;
ll sum[100005];
vector<int> v[100005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
        ++cnt[x],++cnt[y];
        sum[x]+=y,sum[y]+=x;
    }
    for(int i=1;i<=n;++i)if(cnt[i]==1)q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(c[x]) continue;
        c[x]=-1;
        x=sum[x];
        if(c[x]==1){
            puts("First");
            return 0;
        }
        if(c[x]==-1) continue;
        c[x]=1;
        for(int i=0;i<v[x].size();++i){
            int y=v[x][i];
            if(c[y]) continue;
            --cnt[y];
            sum[y]-=x;
            if(!cnt[y]){
                puts("First");
                return 0;
            }
            if(cnt[y]==1)q.push(y);
        }
    }
    for(int i=1;i<=n;++i){
        if(c[i]==-1){
            for(int j=0;j<v[i].size();++j)c[v[i][j]]=0;
        }
    }
    for(int i=1;i<=n;++i){
        if(c[i]==1){
            puts("First");
            return 0;
        }
    }
    puts("Second");
    //system("pause");
    return 0;
}
