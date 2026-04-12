#include<bits/stdc++.h>
using namespace std;
long long eat(long long s,long long p,long long x){
    if(x==0)return 0;
    if(s==1)return 1;
    if(x<=s/2)return eat((s-3)/2,(p-1)/2,x-1);
    else return p/2+1+eat((s-3)/2,(p-1)/2,x-s/2-1);
}
int main(){
    int n;
    cin>>n;
    long long x;
    cin>>x;
    long long s=1,p=1;
    for(int i=0;i<n;i++){
        s=s*2+3;
        p=p*2+1;
    }
    cout<<eat(s,p,x)<<endl;
    return 0;
}