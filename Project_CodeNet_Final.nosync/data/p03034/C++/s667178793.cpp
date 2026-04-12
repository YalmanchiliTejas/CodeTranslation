#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N=100000+10;
typedef long long LL;
int n,s[N];
map<int,LL> sum[N],sum2[N];
vector<int> divs[N];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y); 
}
LL pre[N];
int main() {
    for(int i=1;i<N;i++)for(int j=i;j<N;j+=i) divs[j].push_back(i); 
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&s[i]); 
    for(int i=n-1;i>=0;i--){
        int d=n-1-i;
        for(auto x: divs[d]){
            if(x>=i) continue;
            sum[i][x] = sum[i+x][x] + s[i];
            int r = d / x;
            sum2[i][x] = sum2[i+x][x] + s[x*r];
        }
    }
    LL ans=0;
    for(int a=1;a<n-1;a++) {
        int d=n-1-a;
        for(auto x: divs[d]) {
            //x=a-b
            if(x>=a) continue;
            int b=a-x;
            int g=gcd(a,b);
            LL aa=a/g, bb=b/g;
            if(aa - bb == 1 && aa * a - (aa - 1)*b < n-1) continue;
            LL tmp=sum2[a][a-b]+sum[a][a-b];
            // printf("tmp=%lld, a=%d, b=%d [%d, %d]\n", tmp,a,b,sum2[a][a-b],sum[a][a-b]);
            ans=max(ans,tmp);
        }
    }
    cout<<ans<<endl;
}
/*
a a-b 2a-b 2a-2b 3a-2b 3a-3b
ka-kb = (t+1)a-tb
(k-t-1)a=(k-t)b
k-t-1=b/g
k-t=a/g
a=10, b=9
8 2 10
6 2 8 4 10
*/