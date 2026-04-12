#include <iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef long long int LL;
LL c[110000],p[110000];
int main(void){
    LL n,i,j;
    LL ans=0,x,m;
    bool u=false;
    for(i=0;i<110000;i++){
        c[i]=0;
        p[i]=-1;
    }
    cin>>n>>x>>m;
    for(i=0;i<n;i++){
        ans+=x;
        if(p[x]==-1||u){
            c[x]=ans;//答え保管
            p[x]=i;//場所保管
            x=x*x%m;
        }else{
            u=true;
            j=(n-i-1)/(i-p[x]);//高速ループ回数
            ans+=(ans-c[x])*j;
            i+=j*(i-p[x]);//*/
            x=x*x%m;
        }
    }
    cout<<ans<<endl;
}
