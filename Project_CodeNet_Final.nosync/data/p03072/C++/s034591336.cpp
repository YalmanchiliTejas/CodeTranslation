#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,max=0,n,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(max<=a){
            c++;
            max=a;
        }
    }
    cout<<c<<"\n";
}