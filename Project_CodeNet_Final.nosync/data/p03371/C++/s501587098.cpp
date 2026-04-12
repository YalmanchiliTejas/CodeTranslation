#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int i;
    int v;
    v=a*x+b*y;
    int u=max(x,y);
    int s;
    for(i=0;i<=2*u;i+=2){
        s=c*i;
        if(i/2<x){
            s+=a*(x-i/2);
        }
        if(i/2<y){
            s+=b*(y-i/2);
        }
        if(s<v) v=s;
    }
    cout<<v<<endl;
    
    return 0;
}