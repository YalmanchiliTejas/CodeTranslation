#include <iostream>

using namespace std;

int main()
{
    int n,a[200005],b[200005];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int x=0,y=n-1;
    if(n%2!=0)
        for(int i=n-1; i>=0; i--)
        {
            if(i%2==0)
            {
                b[x]=a[i];
                x++;
            }
            else
            {
                b[y]=a[i];
                y--;
            }
        }
    else
        for(int i=n-1; i>=0; i--)
        {
            if(i%2!=0)
            {
                b[x]=a[i];
                x++;
            }
            else
            {
                b[y]=a[i];
                y--;
            }
        }
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    return 0;
}
