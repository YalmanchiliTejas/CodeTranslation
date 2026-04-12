#include <iostream> 
#include <algorithm> 
#include <cstring> 
#include <cstdio>
#include <vector> 
#include <queue> 
#include <cstdlib> 
#include <iomanip>
#include <cmath> 
#include <ctime> 
#include <map> 
#include <set> 
using namespace std; 
#define lowbit(x) (x&(-x)) 
#define max(x,y) (x>y?x:y) 
#define min(x,y) (x<y?x:y) 
#define MAX 100000000000000000 
#define MOD 1000000007
#define pi acos(-1.0) 
#define ei exp(1) 
#define PI 3.141592653589793238462
#define ios() ios::sync_with_stdio(false)
#define INF 0x3f3f3f3f3f 
#define mem(a) (memset(a,0,sizeof(a))) 
typedef long long ll;
ll n,k,x,m;
priority_queue<ll>q;
int main()
{
    ios();
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        q.push(x);
    }
    k=0;
    while(q.top()+k>=n)
    {
        ll ans=q.top()+k;
        q.pop();
        m=ans/n;
        ans-=m*n;
        k+=m;
        q.push(ans-k);
    }
    printf("%lld\n",k);
    return 0;
}