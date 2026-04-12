#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
if(a+b<=2*c)cout<<x*a+y*b;
else {
    int ans=min(x,y)*2*c;
    int aa=min(x,y);
    x-=aa;y-=aa;
    if(x>0){
        if(a<2*c)ans+=x*a;
        else ans+=2*c*x;
    }
    if(y>0){
        if(b<2*c)ans+=y*b;
        else ans+=2*c*y;
    }
    cout<<ans;
}

}