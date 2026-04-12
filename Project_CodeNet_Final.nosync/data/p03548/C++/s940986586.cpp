#include <bits/stdc++.h>
using namespace std;

int X,Y,Z,a=0;
int main(){
	cin>>X>>Y>>Z;
	X=X-Z;
	while(X>=Y+Z) {
		X=X-(Y+Z);
		a++;
	}
	cout<<a<<endl;
}
