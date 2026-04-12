#include <bits/stdc++.h>
using namespace std;
long ans(long n,long x){
    long bu=(long)pow(2,n+1)-3;
    long pa=(long)pow(2,n)-1;
    if(n==0&&x==1)
        return 1;
    if(x==1)
        return 0;
    if(x<=bu+1)
        return ans(n-1,x-1);
    if(x==bu+2)
        return pa+1;
    if(x==2*bu+3)
        return 2*pa+1;
    if(x>bu+2)
        return pa+1+ans(n-1,x-2-bu);
}
int main(){
    long n,x; cin>>n>>x;
    cout<<ans(n,x);
}