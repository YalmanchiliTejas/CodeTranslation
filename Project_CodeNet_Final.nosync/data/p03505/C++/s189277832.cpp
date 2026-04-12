#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
int main()
{
    cin>>n>>m>>k;
    if(n<=m)
    {
        cout<<"1\n";
        return 0;
    }
    if(m<=k)
    {
        cout<<"-1\n";
        return 0;
    }
    cout<<((n-m)%(m-k)==0?(n-m)/(m-k):(n-m)/(m-k)+1)*2+1<<endl;
    return 0;
}