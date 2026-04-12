#include <bits/stdc++.h>
using namespace std;

int main(){   
    int a,b,c,x,y,ans=0;
    cin >> a >> b >> c >> x >> y;
    if(a+b>2*c){
        ans+=2*c*min(x,y);
    }else{
        ans+=(a+b)*min(x,y);
    }
    if(x>y){
        if(a>2*c){ans+=2*c*(x-y);}else{ans+=a*(x-y);}
    }else{
        if(b>2*c){ans+=2*c*(y-x);}else{ans+=b*(y-x);}
    }
    cout << ans << endl;    
}