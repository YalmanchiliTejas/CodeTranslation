#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

namespace ndifix{

}

int main(){
    int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
    if(a+b<c+c)cout<<x*a+y*b<<endl;
    else cout<<c*2*min(x,y)+(x>y?(c+c<a?c*2*(x-y):a*(x-y)):(c+c<b?c*2*(y-x):b*(y-x)))<<endl;
    return 0;
}