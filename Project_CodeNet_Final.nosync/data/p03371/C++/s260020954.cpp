#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int a,b,c,x,y,mi=1000000000;
    cin>>a>>b>>c>>x>>y;
    for(int i=0;i<=max(x,y);i++)mi=min(mi,(c*2*i)+(max(0,(x-i))*a)+(max(0,(y-i))*b));
    cout<<mi<<endl;
    return 0;
}
