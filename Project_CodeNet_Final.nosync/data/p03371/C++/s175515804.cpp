#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>

using namespace std;

int a,b,c,x,y;
int ans[5];

int main(){

    cin>>a>>b>>c>>x>>y;

    ans[0]=a*x+b*y;
    if(x>y){
        ans[1]=c*2*y+a*(x-y);
        ans[2]=c*2*x;
    }else{
        ans[1]=c*2*x+b*(y-x);
        ans[2]=c*2*y;
    }

    sort(ans,ans+3);


    
    cout<<ans[0]<<endl;
 
    return 0;
}