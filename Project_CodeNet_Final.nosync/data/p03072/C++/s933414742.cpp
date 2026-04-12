#include<iostream>
using namespace std;
int n,cnt,h[105],minf;
main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>h[i];
    minf=h[0];
    for(int i=0;i<n;i++){
        if(minf<=h[i])cnt++;
        if(minf<h[i])minf=h[i];
    }
    cout<<cnt<<endl;
}