#include<iostream>
using namespace std;
int main()
{
    int r,g,b,temp;
    cin>>r>>g>>b;
    temp=(r*100)+(g*10)+b;
    if(temp%4==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
