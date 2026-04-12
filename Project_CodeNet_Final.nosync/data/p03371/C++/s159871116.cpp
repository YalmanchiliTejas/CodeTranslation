#include <bits/stdc++.h>
using namespace std;

int main(void){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    
    int sum=1000000000;
    for(int i=0;i<=max(X,Y);i++){
        sum=min(sum,i*2*C+A*max(0,X-i)+B*max(0,Y-i));
    }
    
    cout<<sum<<endl;
    
}
