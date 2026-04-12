#include <iostream>
using namespace std;


int main() {
	int x,y,z;
	cin>>x>>y>>z;
	int a=(x*10+y)*10+z;

	if(a%4==0)
        cout<<"YES";
    else cout<<"NO";
	return 0;
}
