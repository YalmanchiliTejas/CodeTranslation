#include <bits/stdc++.h>
using namespace std;
int main(){
	 double n=1,x=1;
	cin>>n;
	x=n*800;
	while(n>=15){
		x-=200;
		n-=15;
	}
	cout<<x;
}