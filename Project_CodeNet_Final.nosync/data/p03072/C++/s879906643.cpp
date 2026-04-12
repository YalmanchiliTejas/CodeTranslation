#include<iostream>
using namespace std;
int main()
{
    int arr[21];
    int n,mx=-1,mx2=-1,cnt=1,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=1;i<n;i++)
    {
        if(arr[i]>mx2)
            mx2=arr[i];
        if(arr[i]>=arr[0]&& arr[i]>=mx2)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
