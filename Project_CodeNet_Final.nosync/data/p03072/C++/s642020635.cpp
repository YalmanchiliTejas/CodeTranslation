#include <iostream>

using namespace std;
int a[101],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=1;
    for(int i=2;i<=n;i++)
        {
           int flag=0;

        for(int j=1;j<=i-1;j++)
            if (a[j]>a[i]) flag=1;
        if (flag==0) ans++;
        }
    cout <<ans<< endl;
    return 0;
}
