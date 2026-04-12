#include <iostream>
#include <stack>
#include <vector>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    long long int n;
    long long int k;
    while(cin>>n>>k){
    long long int sum=0;
    long long int i;
    if(k==0)cout<<n*n<<endl;
    else{
    for(i=k+1;i<=n;i++)
    {
        long long int q=n/i;
        long long int r=n%i;
        sum+=q*max((long long int)0,i-k);
        sum+=max((long long int)0,r-k+1);
    }
    cout<<sum<<endl;
    }
    }
    return 0;
}
