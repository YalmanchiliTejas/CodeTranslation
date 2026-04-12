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
#define N 1010


int main(void){
int a[10001];
int b[100000];
int n,m,x;

int ans;
scanf("%d",&n);
f(i,10001)a[i]=0;
f(i,100000)b[i]=0;
m=0;
f(i,n){
scanf("%d",&b[i]);
if(m<b[i])m=b[i];
}
x=m;
f(i,m){
if(m%(m-i)==0)x=m-i;
a[m-i]=x+i-m;
}
ans=0;
f(i,n)ans+=a[b[i]];
printf("%d\n",ans);




return 0;
}
