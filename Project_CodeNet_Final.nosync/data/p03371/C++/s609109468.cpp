#include <iostream>
typedef long long ll;
using namespace std;

int main(){    
    ll a,b,c,x,y,ans;
    cin>>a>>b>>c>>x>>y;  
    if(x<y){
        swap(a,b);
        swap(x,y);} 
    ans=min(c*(x*2),c*(y*2)+a*(x-y));  
    cout<<min(ans,a*x+b*y)<<endl; 
    return 0;}