#include<iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    if(a >= 15) cout<<((a * 800) - ((a / 15) * 200))<<endl;
    else cout<<a * 800<<endl;
    return 0;
}
