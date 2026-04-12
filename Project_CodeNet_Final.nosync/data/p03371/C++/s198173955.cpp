#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    long long int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    long long int ans1,ans2,ans3;
    if(x>y){
        ans1=2*c*y+a*(x-y);
    }else{
        ans1=2*c*x+b*(y-x);
    }
    ans2=a*x+b*y;
    ans3=2*c*max(x,y);
    cout<<min(ans1,min(ans2,ans3))<<endl;
}