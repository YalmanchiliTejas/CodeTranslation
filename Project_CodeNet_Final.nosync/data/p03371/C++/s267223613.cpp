#include<bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    c*=2;
    int ans=1000000000;
    for(int i=0;i<=100000;i++){
        ans=min(ans,c*i+a*max(0,x-i)+b*max(0,y-i));
    }
    cout<<ans<<endl;
    return 0;
}
