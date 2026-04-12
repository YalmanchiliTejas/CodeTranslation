#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
#define LL long long int 
int main() 
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL N;
    cin  >> N;
    vector<LL> arr(N);
    for(auto &it:arr)
    {
        cin>>it;
    }
    vector<LL> prefix(N);
    prefix[N-1]=arr[N-1];
    for(LL i=N-2;i>=0;i--)
    {
        prefix[i]=(prefix[i+1]+arr[i])%mod;
    }
    LL prod=0;
    for(LL i=0;i<N-1;i++)
    {
        prod=(prod +(arr[i]*prefix[i+1] ) %mod )%mod;
    }
    cout<<prod;

}
 
 