#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    long ans;
    if(x>=y){
        ans=y*min(a+b,c*2)+(x-y)*min(a,c*2);
    }
    else{
        ans=x*min(a+b,c*2)+(y-x)*min(b,c*2);
    }
    cout<<ans<<endl;
}