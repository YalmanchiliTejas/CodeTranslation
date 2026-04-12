#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    int c = 1;
    int curr_max =a[0];
    for(int i = 1;i<n;i++)
    {
        if(a[i]>=curr_max)
        {
            c++;
            curr_max = a[i];
        }
    }
    cout<<c;
}
