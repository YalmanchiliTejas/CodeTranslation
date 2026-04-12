#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int h[110];
    int largest_sofar=-999;
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
    {
        if(largest_sofar<=h[i])
        {
            sum++;
            largest_sofar=h[i];
        }
    }
    cout<<sum<<"\n";
    return 0;
}
