#include <iostream>
using namespace std;
typedef long long ll;
ll n,k,s[51],t[51];
ll f(ll a,ll b){
    if(a==1)return 0;
    if(a<(s[b]+1)/2-1)return f(a-1,b-1);
    if(a==(s[b]+1)/2-1)return t[b-1];
    if(a==(s[b]+1)/2)return t[b-1]+1;
    if(a<s[b]-1)return f(a-(s[b]+1)/2,b-1)+t[b-1]+1;
    else return 2*t[b-1]+1;
}
int main(void){
    cin>>n>>k;
    s[0]=1;
    t[0]=1;
    for(int i=1;i<=50;i++){
       s[i]=s[i-1]*2+3;
       t[i]=t[i-1]*2+1;
    }
    //for(int i=0;i<51;i++)cout<<t[i]<<endl;
    cout<<f(k,n)<<endl;
}
