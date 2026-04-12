#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,h;
    int ans=0,wall=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h;
        if(h>=wall){
            wall=h;
            ans++;
        }
    }
    cout<<ans<<endl;



    return 0;
}