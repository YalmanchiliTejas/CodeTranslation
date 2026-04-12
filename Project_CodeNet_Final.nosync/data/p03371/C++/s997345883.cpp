#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX 1100
using namespace std;


int main(){
    long long pa,pb,pab,x,y,sum=0,x_y;
    cin>>pa>>pb>>pab>>x>>y;
    x_y=min(x,y);
    if(pa+pb>=2*pab){
        sum+=((x_y)*2*pab);
        if(x>=y) {
            x-=y;
            sum+=min(x*2*pab,x*pa);
        }
        else {
            y-=x;
            sum+=min(y*2*pab,y*pb);
        }
    }
    else {
        sum+=pa*x+pb*y;
    }
    cout<<sum<<endl;
    return 0;
}
