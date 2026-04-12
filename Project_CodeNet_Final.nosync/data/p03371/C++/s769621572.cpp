#include <iostream>
#include <string>
#include <cstring>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>
using namespace std;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ans=0;
    if(x>=y){
        if(a+b>=c*2)ans+=c*2*y;
        else ans+=(a+b)*y;
        if(a>=c*2)ans+=c*2*(x-y);
        else ans+=a*(x-y);
    }else{
        if(a+b>c*2)ans+=c*2*x;
        else ans+=(a+b)*x;
        if(b>c*2)ans+=c*2*(y-x);
        else ans+=b*(y-x);
    }
    cout<<ans<<endl;
    return 0;
}

