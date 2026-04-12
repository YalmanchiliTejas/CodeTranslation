#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
#define maxx 110000
typedef long long ll;
int a[100010];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    int ans =1;
    int high = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>=high)
        {
            ans++;
            high=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}