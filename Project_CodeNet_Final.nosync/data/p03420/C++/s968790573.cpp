#include <iostream>
using namespace std;
int main(){
    int j;
    long long i,n,k;
    i=0;
    cin >> n >> k;
    if(k==0){
       cout << n*n << endl;
    }else{
    for(j=0;j<=n-k-1;j++){
        if(n%(k+j+1)<k-1){
        i += (n+1-k)/(k+j+1)*(j+1)+ (j+1);
    }else{
        i += (n+1-k)/(k+j+1)*(j+1) + (n-k+1)%(k+j+1);
    }
    }
cout << i << endl;
}
}