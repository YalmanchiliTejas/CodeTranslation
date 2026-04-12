#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,i,sm,bi;
int main(void){
    cin>>n;
    int x[n],y[n];
    for(i=-1;++i-n;){
        cin>>x[i];
        y[i]=x[i];
    }
    sort(x,x+n);
    sm=x[n/2-1];
    bi=x[n/2];
    for(i=-1;++i-n;){
        if(y[i]>sm)cout<<sm<<endl;
        else cout<<bi<<endl;
    }
    return 0;
}