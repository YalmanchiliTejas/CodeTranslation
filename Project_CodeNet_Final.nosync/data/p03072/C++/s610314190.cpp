#include<iostream>
using namespace std;
int main()
{
    long long int n,i,j,c=0,max=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        if(max<=a[i])
        {
            max=a[i];
            c++;
        }
    }

    cout<<c<<endl;
    return 0;

}