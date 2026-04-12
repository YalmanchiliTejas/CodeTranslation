#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c,x,y;
int main(){
    cin>>a>>b>>c>>x>>y;
    a=min(a,c*2); b=min(b,c*2); c=min(a+b,c*2);
    int ab=min(x,y);
    cout<<ab*c+a*(x-ab)+b*(y-ab);
}