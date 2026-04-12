#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int a, b, c, x, y, ans=0;
    cin>>a >>b >>c >>x >>y;
    if(a+b >= 2*c){
        ans+=min(x, y)*2*c;
        if(x<y){
            ans+=(y-x)*min(b, 2*c);
        }
        if(x>y){
            ans+=(x-y)*min(a, 2*c);
        }
    }else{
        ans+=a*x+b*y;
    }
    
    cout<<ans<<endl;
    return 0;
}