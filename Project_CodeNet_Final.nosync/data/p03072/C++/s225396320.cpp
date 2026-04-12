#include<iostream>
using namespace std;
int main()
{
    int a[30];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int max=a[0],sum=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>=max)
        {
            sum++;
            max=a[i];
        }
    }
    cout<<sum<<endl;
}
