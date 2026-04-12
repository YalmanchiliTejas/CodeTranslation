#include<bits/stdc++.h>
using namespace std;
int a[100001];
int save=0;
bool first;
int main()
{
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int index;
        cin>>index;
        first=false;
        for(int j=save;j<n;j++)
        {
            if(a[j]>=index&&first==false)
            {
                cout<<j<<endl;
                first=true;
                 save=j;
                 break;
            }
        }
        if(first==false)
            {
                cout<<n<<endl;
                save=n;
            }
    }
    return 0;
}

