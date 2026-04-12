#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
int main()
{
    int r,g,b;
    while(cin>>r>>g>>b)
    {
        int s=r*100+g*10+b;
        if(s%4==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
