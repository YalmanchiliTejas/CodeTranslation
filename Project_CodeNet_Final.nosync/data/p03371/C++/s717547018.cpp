#include<iostream>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    long long ans=1e10;
    for(int i=0;i<=1e5;i++){
        long long tmp=i*2*c+max(0,x-i)*a+max(0,y-i)*b;
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}