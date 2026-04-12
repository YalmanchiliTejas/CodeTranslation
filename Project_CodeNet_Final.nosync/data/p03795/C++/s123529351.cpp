#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    int N=0,X=0,Y=0,Z=0;
    cin>>N;

    X=(N/15)*200;
    Y=N*800;
    Z=Y-X;
    cout<<Z<<"\n";
    return 0;

}