#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
#define LL long long int 
int main() 
{
 
   
   
    LL N;
    cin  >> N;
    vector<LL> arr(N);
    for(auto &it:arr)
    {
        cin>>it;
    }
    vector<LL> p(N);
    p[N-1]=arr[N-1];
    for(LL i=N-2;i>=0;i--)
    {
        p[i]=(p[i+1]+arr[i])%mod;
    }
    LL m=0;
    for(LL i=0;i<N-1;i++)
    {
        m=(m +(arr[i]*p[i+1] ) %mod )%mod;
    }
    cout<<m;
 
}