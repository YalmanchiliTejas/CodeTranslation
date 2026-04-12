#include <bits/stdc++.h>
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    ll ans=INF;
    for(int i=0;i<=max(x,y);i++){
        ll tmp=2*c*i;
        if(x>i)tmp+=min(a,2*c)*(x-i);
        if(y>i)tmp+=min(b,2*c)*(y-i);
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
 return 0;   
}