#include<iostream>
using namespace std;
int main()
{
	int x, n, y, z=0, i, t;
	cin>>n;
	if(n>=1 && n<=100){
			z=800*n;
		if(n>15){
			i=n/15;
			t=z-(i*200);
			cout<<t;
		}
		else{
			cout<<z;
		}
	}
	else{
		cout<<"error";
	}
	return 0;
}