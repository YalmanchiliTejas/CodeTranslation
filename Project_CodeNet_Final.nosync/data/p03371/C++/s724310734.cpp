#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
        int a,b,c,x,y;
        cin >> a >> b >> c >> x >> y;

        int ans,m1,m2;
        if(2*c-a-b>=0) m1=a*x+b*y;
        else m1=a*x+b*y+(2*c-a-b)*min(x,y);

        if(x<y){
                if(2*c-b>=0) m2=b*y+(2*c-b)*x;
                else m2=b*y+(2*c-b)*y;
        }else if(x>y){
                if(2*c-a>=0) m2=a*x+(2*c-a)*y;
                else m2=a*x+(2*c-a)*x;
        }else{
                m2=min(a*x+b*y,2*c*max(x,y));
        }

        ans=min(m1,m2);

        cout << ans << endl;

        return 0;
}
