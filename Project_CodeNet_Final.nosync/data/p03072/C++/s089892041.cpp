#include<bits/stdc++.h>
using namespace std;
int a,b,c=0,d,e,f,g,h,k,n,m,t,pre=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d;
        if(d>=pre){
            pre=d;
            c++;
        }
    }
    cout<<c<<endl;
}