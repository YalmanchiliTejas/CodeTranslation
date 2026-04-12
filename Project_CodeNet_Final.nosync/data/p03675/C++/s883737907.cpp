#include <iostream>
using namespace std;
int main(void){
    int n,s,l,f=0;
    long long a[200000],b[200000];
    cin>>n;
    s=0;l=n-1;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>=0;i--){
        if(f==0){b[s]=a[i];s++;f=1;}
        else {b[l]=a[i];l--;f=0;}
    }
    for(int i=0;i<n-1;i++)cout<<b[i]<<" ";
    cout<<b[n-1];
    return 0;
}