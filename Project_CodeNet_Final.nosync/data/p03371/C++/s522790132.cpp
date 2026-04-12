#include <bits/stdc++.h>

using namespace std;

//#define MD 100010

int main(){
    long int a,b,c,x,y,ans=0;
    cin>>a>>b>>c>>x>>y;
    if(c>=a && c>=b){
        ans+=(a*x);
        ans+=(b*y);
    }else{
        if(min(x,y)==x){
            long int tmp1=(2*c*x+(y-x)*b);
            long int tmp2=(2*c*y);
            long int tmp3=(a*x+b*y);
            ans=min(tmp1,min(tmp2,tmp3));
        }else{
            long int tmp1=(2*c*y+(x-y)*a);
            long int tmp2=(2*c*x);
            long int tmp3=(a*x+b*y);
            ans=min(tmp1,min(tmp2,tmp3));
        }
    }
    
    /*else if(c<a && c<b){
        if(min(a,b)==a){
            ans+=(2*y*c);
        }else{
            ans+=(2*x*c);
        }*/
    cout<<ans<<endl;
    
    return 0;
}