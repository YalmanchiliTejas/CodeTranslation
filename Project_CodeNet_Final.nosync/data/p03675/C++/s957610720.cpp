#include<iostream>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN];


int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;++i)   
        {
            cin>>a[i];
        }
        if(n&1)
        {
            cout<<a[n];
            for(int i=n-2;i>=1;i-=2)
                cout<<" "<<a[i];
            for(int i=2;i<=n-1;i+=2)
                cout<<" "<<a[i];
            cout<<endl;
        }else
        {
            cout<<a[n];
            for(int i=n-2;i>=2;i-=2)
                cout<<" "<<a[i];
            for(int i=1;i<=n-1;i+=2)
                cout<<" "<<a[i];
            cout<<endl;
        }
    }
    return 0;
}