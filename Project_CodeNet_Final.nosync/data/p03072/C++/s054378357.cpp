#include <bits/stdc++.h> 
using namespace std; 
int main()
{
    int n,i,ans=0,count=0,j;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
    cin >> a[i];
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[i])
            {
                ans++;
                break;
            }
        }
        if(ans==0)
        count++;
        ans=0;
    }
    cout << count;
    return 0;
}
