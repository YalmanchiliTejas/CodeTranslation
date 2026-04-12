#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200100


int main(void){
map<long long,long long>m;
set<long long>ss;
long long s,ans;
int n;
long long x;
scanf("%d",&n);
s=0;
ans=0;
ss.insert(s);
m[s]=0;
f(i,n){
scanf("%lld",&x);
s+=x;
if(ss.count(s)==1){
ans=max(ans,i+1-m[s]);
}
else{
ss.insert(s);
m[s]=i+1;
}
}
printf("%lld\n",ans);

return 0;
}
