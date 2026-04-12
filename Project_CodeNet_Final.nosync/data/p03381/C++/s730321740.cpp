#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
using namespace std;
int main(void){
    int N;
    cin>>N;
    long X[N],x[N];
    for(int i=0;i<N;i++){
        cin>>X[i];
        x[i]=X[i];
    }
    sort(x,x+N);
    int mid1=x[N/2]; int mid2=x[N/2-1];
    for(int i=0;i<N;i++){
        if(X[i]>=mid1){cout<<mid2<<endl;}
        else {cout<<mid1<<endl;}
    }
    return 0;
}