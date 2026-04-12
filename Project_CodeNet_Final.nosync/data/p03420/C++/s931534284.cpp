#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    long long sum=0;
    for(int b=k+1;b<=n;b++)
    {
        int s1=n%b-k<0?0:n%b-k+1;
        sum+=(n/b)*(b-k)+s1;
    }
    if(k==0)sum-=n;
    cout<<sum<<endl;
    return 0;
}
