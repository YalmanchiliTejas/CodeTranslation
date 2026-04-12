#include <iostream>
using namespace std;

typedef long long ll;
int n;
ll a[100001],d[3002][3002],INIT=-1e18;

ll p(int l, int r){
    if(d[l][r]!=INIT)return d[l][r];
    if(l==r-1)return d[l][r]=(1-((n*3-r-l)%2)*2)*a[l];
    if((n*3-l-r)%2==0){
        return d[l][r]=max(p(l+1, r)+a[l], p(l, r-1)+a[r-1]);
    }else{
        return d[l][r]=min(p(l+1, r)-a[l], p(l, r-1)-a[r-1]);
    }
}

int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            d[i][j]=INIT;
        }
    }
    ll ans=p(0, n);
    cout<<ans<<endl;
}
