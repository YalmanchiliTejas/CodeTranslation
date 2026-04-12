#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int c=0,g,k=0;
    for(int i=0;i<n;i++){
        cin>>g;
        if(k<=g){
            c++;
            
        }
        k=max(k,g);
    }
    cout<<c<<endl;
}