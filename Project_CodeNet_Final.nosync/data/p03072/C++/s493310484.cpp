#include<bits/stdc++.h>
using namespace std;
int main()
{

    int a, n,b, s=1,k=0;

    cin>>n;
    int ar[n+2];
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }

    for(int i=n-1; i>=1; i--)
    {
        for(int j=0; j<=i-1; j++)
        {
            if(ar[i]>=ar[j])
            {
                continue;
            }
            k++;
            break;
        }
        if(k==0)
        {
            s++;

        }
        else{
            k=0;
        }

    }
    cout<<s<<endl;
}
