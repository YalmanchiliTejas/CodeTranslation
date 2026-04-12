#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[25];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        int flag=1;
        for(int j=0;j<i;j++){
            if(a[j]>a[i]){
               flag=0;
            }
        }
        if(flag==1){cnt++;}
    }
    cout<<cnt;
    return 0;
}
