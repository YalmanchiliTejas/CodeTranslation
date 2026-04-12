#include <iostream>
using namespace std;

int main() {
    int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    
    long long ans,ans2;
    
    ans = min(a*x+b*y, 2*c*max(x,y));
    
    if(x>=y)ans2 = 2*c*min(x,y)+ a*(x-y);
    if(x< y)ans2 = 2*c*min(x,y)+ b*(y-x);
    
    ans = min(ans,ans2);

    cout<<ans<<endl;

	return 0;
}