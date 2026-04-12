#include "bits/stdc++.h"
using namespace std;

int main() {
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    cout<<min(min(a*x+b*y,(x-min(x,y))*a+(y-min(x,y))*b+min(x,y)*2*c),max(x,y)*2*c)<<"\n";
}