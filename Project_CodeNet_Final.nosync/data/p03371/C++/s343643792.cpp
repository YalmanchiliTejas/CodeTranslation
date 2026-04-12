#include <bits/stdc++.h>
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
using namespace std;
int main(void){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=0;
    if(2*c<=a+b and 2*c<=a and 2*c<=b){
        ans=2*c*max(x,y);
    }else if(2*c<=a+b){
        ans=2*c*min(x,y);
        if(x<=y){
            ans+=(y-x)*min(b,2*c);
        }else{
            ans+=(x-y)*min(a,2*c);
        }
    }else{
        ans=x*a+y*b;
    }
    cout<<ans<<endl;
 return 0;   
}