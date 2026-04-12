#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n,x;
    cin>>n>>x;
    long long s=1,t=1;
    for(int i=0;i<n;i++) s=s*2+3,t=t*2+1;
    long long ans=0;
    while(x>0){
        if(s/2+1<=x){
            ans+=t/2+1;
            if(x==s) x=x-s/2-2;
            else x=x-s/2-1;
            s=s/2-1;
            t=t/2;
        }
        else{
            s=s/2-1;
            t=t/2;
            x=x-1;
        }
    }
    cout<<ans;
}