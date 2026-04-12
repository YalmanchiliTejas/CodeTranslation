#include <iostream>
using namespace std;
#define ll long long int
int main() {

    ll x,y,z,c=0;
    cin>>x>>y>>z;
    x-=z;
    while(x>=y+z)
    {
        x=x-y-z;
        c++;
    }
    cout<<c;
	return 0;
}