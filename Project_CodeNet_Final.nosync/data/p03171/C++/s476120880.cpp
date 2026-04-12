#include<iostream>
using namespace std;
typedef long long ll;
ll N,a[10000],s,memory[3003][3003];
ll dp(ll left,ll right)
{
    if (memory[left][right]!=0){
        return memory[left][right];
    }
    if (left>right) return 0;
    ll x1=a[left]+min(dp(left+2,right),dp(left+1,right-1));
    ll x2=a[right]+min(dp(left+1,right-1),dp(left,right-2));
    memory[left][right]=max(x1,x2);
    return max(x1,x2);
}
int main()
{
   cin>>N;
   s=0;
   for (int i=1;i<=N;++i){
        cin>>a[i];
        s+=a[i];
}
    cout<<2*dp(1,N)-s;

}