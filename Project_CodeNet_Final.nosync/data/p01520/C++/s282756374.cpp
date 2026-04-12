#include<iostream>
using namespace std;
int main(){

    int n,t,e,a;
    cin>>n>>t>>e;
    for(int i=1;i<=n;i++){
        cin>>a;
        for(int j=t-e;j<=t+e;j++){
            if(j%a==0){
                cout<<i<<endl;
                goto end;
            }
        }
        if(i==n)cout<<"-1"<<endl;
    }
    end:
    return 0;

}