#include <bits/stdc++.h>

using namespace std;

int main() {
int n,c=1;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int flag;
for(int i=1;i<n;i++)
{
    flag=0;
    for(int j=0;j<=i;j++)
    {
        if(arr[j]>arr[i])
        {
            flag=1;
            break;
        }
    }
        if(flag==0)
            c++;
}
cout<<c;

}
