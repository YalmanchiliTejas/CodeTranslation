#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,n,c=0,max=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>=max) c++;
        if(a>max) max=a;
    }
    cout<<c<<"\n";
}