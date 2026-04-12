#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a,b,c,x,y,ans=2000000000;
    cin>>a>>b>>c>>x>>y;
    int M=max(x,y);
    for(int i=0;i<=2*M;i+=2){
        int na=max(x-i/2,0);
        int nb=max(y-i/2,0);
        ans=min(ans,a*na+b*nb+c*i);
    }
    cout<<ans<<endl;
}
