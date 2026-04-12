#include<iostream>
using namespace std;
int main()
{
    int x;
    x=1;
    if(x>=1 && x<=9)
    {
        cin>>x;
        if(x==3||x==5||x==7)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
    }
    return 0;
}
