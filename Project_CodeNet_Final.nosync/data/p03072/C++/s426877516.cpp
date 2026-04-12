#include<iostream>。
using namespace std;
int h[25];
int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
        int flag=1;
        for(int j=0;j<i;j++)
        {
            if(h[j]>h[i])
            {
                flag=0;
                break;
            }
        }
        if(flag) count++;
    }
    cout<<count<<endl;
}
