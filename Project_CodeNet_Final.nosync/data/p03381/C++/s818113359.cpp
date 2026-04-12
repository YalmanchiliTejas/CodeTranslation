#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,a,b;
    cin>>n;
    long long int x[n+5],y[n+5];
    for(int i=0;i<n;i++){
        cin>>y[i];
        x[i]=y[i];
    }
    
    sort(x,x+n);
    a=x[(n/2)-1];
    b=x[n/2];
    for(int j=0;j<n;j++){
        if(y[j]>=b){
            cout<<a<<endl;
        }
        else{
            cout<<b<<endl;
        }
    }
    return 0;
}
