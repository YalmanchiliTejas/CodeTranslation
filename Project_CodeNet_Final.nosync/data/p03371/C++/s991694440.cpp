#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    a=min(a,2*c);
    b=min(b,2*c);
    c=min(2*c,a+b);
    if(x<y){
        cout<<x*c+(y-x)*b<<endl;
    }
    else{
        cout<<(x-y)*a+y*c<<endl;
    }
    return 0;
}
