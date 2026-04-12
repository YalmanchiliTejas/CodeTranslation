#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long lld;
typedef pair<int,int> pii;

lld n,k,fin;
int main(){
    scanf("%lld%lld",&n,&k);
    for(lld b=k+1;b<=n;b++){
        lld p=(n-b+1)/b,r=max(n-b*(p+1)-k+1,0ll);
        if(k==0) fin--;
        fin+=(p+1)*(b-k)+r;
        //printf("%lld %lld %lld %lld\n",b,p,r,(p+1)*(b-k)+r);
    }
    printf("%lld\n",fin);
    return 0;
}
