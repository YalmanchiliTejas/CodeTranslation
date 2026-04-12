#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int c=1;
    int val = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>=val){
            c++;
            val=a[i];
        }
    }
    cout<<c<<'\n';
    return 0;
}
