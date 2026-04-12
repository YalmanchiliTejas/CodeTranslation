#include <iostream>
using namespace std;
int main() {
    long n, k, m, s;
    s = 0;
    cin>>n>>k;
    if(k == 0){
        cout<<n*n;
    }
    else{
    for(m=k+1;m<n+1;m++){
        s = s + (m-k)*((n-n%m)/m);
        if((n%m)>=k){
            s = s + (n%m)-k+1;
        }
    }
    cout<<s;
    }
}
