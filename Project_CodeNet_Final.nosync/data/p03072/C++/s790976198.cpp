#include<iostream>
using namespace std;
int main()
{
    int n,i,k=1,Max=0;
    int a[1000]={0};
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>Max)
            Max=a[i];
        if(a[i]>=Max && i!=0)
            k++;
    }
    cout<<k<<endl;
    return 0;
}
