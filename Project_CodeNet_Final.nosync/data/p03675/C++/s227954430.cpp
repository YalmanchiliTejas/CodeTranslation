#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int arr[300000];
int main()
{
    int n,i,j;
    vector<long long int>v;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    if(n%2==0)
    {
        for(i=0; i<n; i++)
        {
            if((i+1)%2==0)
            {
                v.push_back(arr[i]);
            }
        }
        reverse(v.begin(), v.end());
        for(i=0; i<n; i++)
        {
            if((i+1)%2==1)
            {
                v.push_back(arr[i]);
            }
        }
        for(j=0; j<v.size(); j++)
        {
            cout<<v[j]<<" ";
        }
    }
    else
    {
        for(i=0; i<n; i++)
        {
            if((i+1)%2==1)
            {
                v.push_back(arr[i]);
            }
        }
        reverse(v.begin(), v.end());
        for(i=0; i<n; i++)
        {
            if((i+1)%2==0)
            {
                v.push_back(arr[i]);
            }
        }
        for(j=0; j<v.size(); j++)
        {
            cout<<v[j]<<" ";
        }
    }
    return 0;
}
