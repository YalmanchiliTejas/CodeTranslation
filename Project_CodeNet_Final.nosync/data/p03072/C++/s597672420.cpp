#include<bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#define mil 200001

using namespace std;


int main()
{
    int n,m,count = 0;
    cin>>n;
    int arr[mil];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int initial = arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i] >= initial)
        {
            count++;
            initial = arr[i];
        }
    }
    cout<<count;


}
