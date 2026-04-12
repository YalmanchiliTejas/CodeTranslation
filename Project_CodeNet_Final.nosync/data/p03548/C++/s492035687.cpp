#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int x,y,z,d;
    cin >> x >> y >> z;
    x -= z;
    d = x / (y + z);
    cout<<d;
}