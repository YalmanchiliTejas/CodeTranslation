#include <iostream>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int count=1;
    n=n-m-k*2;
    while(n>=(m+k)){
        n-=(m+k);
        count++;
    }
    cout<<count<<endl;
    return 0;
}