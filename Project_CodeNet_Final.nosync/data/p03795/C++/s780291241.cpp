#include <iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    if(x<15)
        cout<<x*800;
    else
        cout<<(800*x)-((x/15)*200);


}