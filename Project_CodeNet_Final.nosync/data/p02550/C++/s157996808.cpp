#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=1e5+5,M=20;
ll n,sum[N][M+1],ans;
int x,m,nex[N][M+1];
void init(){
	 for(int i=0;i<m;++i){
        nex[i][0]=(ll)i*i%m;
        sum[i][0]=nex[i][0];
    }
}
int main(){
    cin>>n>>x>>m;
	ll ans=x;
	init();
    for(int i=1;i<=M;++i){
        for(int j=0;j<m;++j){
            nex[j][i]=nex[nex[j][i-1]][i-1];
            sum[j][i]=sum[j][i-1]+sum[nex[j][i-1]][i-1];
        }
    }
    n-=1;
    ll a=n/(1<<M),b=n%(1<<M);
	int now=x;
    for(int i=1;i<=a;++i){
        ans+=sum[now][M];
        now=nex[now][M];
    }
    for(int j=M-1;j>=0;--j) if(b>>j&1){
            ans+=sum[now][j];
            now=nex[now][j];
    }
    cout<<ans<<endl;
}