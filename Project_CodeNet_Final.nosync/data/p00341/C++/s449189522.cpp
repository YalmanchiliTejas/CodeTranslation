#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[12];
    for(int i=0;i<12;i++){
        cin>>a[i];
    }
    sort(a,a+12);
    for(int i=0;i<12;i+=2){
        if(a[i]!=a[i+1]){
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}
