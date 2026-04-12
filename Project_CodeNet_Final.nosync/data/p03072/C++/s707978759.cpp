#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[50]= {0};
    int cnt=1,now=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];

    }
    now=arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]>=now)
        {
            now=arr[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
