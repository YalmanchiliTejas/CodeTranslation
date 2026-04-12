#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int amari=a;
    if(x<y) amari=b;
    
    cout<<min(min(max(x,y)*2*c,a*x+b*y),min(x,y)*2*c+amari*abs(x-y))<<endl;
    
    return 0;
}