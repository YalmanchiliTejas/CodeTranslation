#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
    cin >> n;
    int arr[n];
    int count=1;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    int temp;
    temp=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=temp)
        {
            count=count+1;
            temp=arr[i];
        }
    }
    
   cout << count << endl;

}