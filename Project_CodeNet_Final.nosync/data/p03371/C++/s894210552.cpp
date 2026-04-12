#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    long a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    long n=min(x,y);
    long ans=0;
    ans+=min((a*n+b*n),(2*c*n));
    long m=max(x-n,y-n);
    if (x>y){
        ans+=min((a*m),(2*c*m));
    }
    else if(x<y){
        ans+=min((b*m),(2*c*m));
    }
    cout<<ans;
    return 0;
}