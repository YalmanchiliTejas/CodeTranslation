#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i;
    int j;
    int count = 0;
    int check = 0;
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(i=n-1;i>=0;i--)
    {
        check = 0;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[i])
            {
                check = 1;
                break;
            }
        }
        if(check==0)
        {
            count++;
        }
    }
    cout << count;
}