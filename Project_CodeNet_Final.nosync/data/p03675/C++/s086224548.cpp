#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int j=n/2,p=n/2,cnt=1;
    if(n==1){
        cout<<a[0];
        return 0;
    }
    if(n%2==1){
        int p=n-1;
        while(p>=0){
            cout<<a[p]<<" ";
            p-=2;
        }
        p=1;
        while(p<n-1){
            cout<<a[p]<<" ";
            p+=2;
        }
    }else{
        int p=n-1;
        while(p>0){
            cout<<a[p]<<" ";
            p-=2;
        }
        p=0;
        while(p<n-1){
            cout<<a[p]<<" ";
            p+=2;
        }
    }


    return 0;
}
