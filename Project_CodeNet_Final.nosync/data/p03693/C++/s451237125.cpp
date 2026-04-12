#include <iostream>
using namespace std;
int main ()
{
    int r,g,b;
    cin>>r;
    cin>>g;
    cin>>b;
    if((2*g+b)%4==0)
        cout<<"YES";
    else
        cout<<"NO";
    
}