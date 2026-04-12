#include <iostream>
using namespace std;
int main(void){
    int n,a[100000],b=0,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>=b){
            c++;
            b=a[i];
        }
    }
    cout<<c;
    }