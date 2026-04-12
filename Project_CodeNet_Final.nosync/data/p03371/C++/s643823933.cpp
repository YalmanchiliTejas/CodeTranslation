#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int both = min(a+b,c*2),aonly = min(a,2*c),bonly = min(b,2*c),com = min(x,y);
    char m = (x>y?'x':'y');
    int ans =0;
    ans += both*com;
    if(m=='x')ans += aonly*(x+y-2*com);
    else ans += bonly*(x+y-2*com);
    cout<<ans<<endl;
}
