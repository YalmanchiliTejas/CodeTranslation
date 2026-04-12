#include <iostream>
using namespace std;
int main() {
    string a;
    int n,i,b;
    cin>>n>>a>>b;
    for (i=0;i<n;i++){
        if (a[i]!=a[b-1]){
            a[i]='*';
        }
    }
    cout<<a;
    return 0;
}