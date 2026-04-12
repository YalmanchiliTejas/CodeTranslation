#include<bits/stdc++.h>
using namespace std;

int a,b,c,x,y;

int main(){
    cin>>a>>b>>c>>x>>y;  
    int ans=min(a+b,2*c)*min(x,y);
    if(x>y)
        ans+=min(a,2*c)*(x-y);
    else
        ans+=min(b,2*c)*(y-x);
    cout << ans << endl;
}