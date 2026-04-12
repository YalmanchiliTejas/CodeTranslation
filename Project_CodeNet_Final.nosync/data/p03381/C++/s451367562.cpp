#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x[200000];
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int tx[200000];
    for(int i=0; i<n; i++) tx[i]=x[i];
    sort(tx, tx+n);
    int midr=tx[n/2];
    int midl=tx[n/2-1];
    for(int i=0; i<n; i++){
        if(midr<=x[i]) cout<<midl<<endl;
        else cout<<midr<<endl;
    }
    return 0;
}
