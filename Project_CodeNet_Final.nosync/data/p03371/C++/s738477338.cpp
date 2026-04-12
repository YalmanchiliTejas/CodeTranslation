#include<bits/stdc++.h>

using namespace std;

#define p 1000000000000000000

int main()

{

    unsigned long long a,b,c,x,y,one=p,two=p,three=p,four=p,five=p;
    cin>>a>>b>>c>>x>>y;
    one=x*a+y*b;
    if(x>=y){
    two=(2*y)*c+(x-y)*a;
    four=(2*x)*c;
    }
    if(x<=y){
        three=(2*x)*c+(y-x)*b;
        five=(2*y)*c;
    }
    cout<<min(one,min(two,min(three,min(four,five))))<<endl;
    return 0;
}
