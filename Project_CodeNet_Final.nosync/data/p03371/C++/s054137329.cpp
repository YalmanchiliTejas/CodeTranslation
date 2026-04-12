#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    
    int sa=min(x,y), amari;
    int ha=c*(sa*2);
    int ha2=c*(max(x,y)*2);
    
    if(x<y){
        amari=b*abs(x-y);
    }else if(x>y){
        amari=a*abs(x-y);
    }
    
    int ans1=min(amari+ha, ha2);
        
    int ans2=a*x+b*y;
    
    cout<<min(ans1,ans2)<<endl;
    
  
}
