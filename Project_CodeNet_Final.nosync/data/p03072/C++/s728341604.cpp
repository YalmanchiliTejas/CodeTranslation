#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a,i,j,c=0;
    cin>>n;
    long long A[n];
    for(i=0;i<n;i++)
    cin>>A[i];
    for(i=0;i<n-1;i++)
    if(A[i]<=A[i+1])c++;
    else
        A[i+1]=A[i];

    cout<<c+1<<endl;
    return 0;
}
