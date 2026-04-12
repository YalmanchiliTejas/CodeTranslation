#include<bits/stdc++.h>
using namespace std;
int ara[50];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>ara[i];
    int res=1;

    for(int i=1; i<n; i++)
    {
        int p=1;
        for(int j=0; j<i; j++)

            if(ara[j]>ara[i])
                p=0;

        if(p)
            res++;
    }
    cout<<res<<endl;
    return 0;
}
