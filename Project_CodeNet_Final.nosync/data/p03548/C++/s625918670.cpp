#include <iostream>
using namespace std;
int main(){
	int i,j,k,n=0,x,y,z;
	cin>>x>>y>>z;
	x-=z;
	y+=z;
	while(x>=y){
		x-=y;
		n++;
	}
	cout<<n<<endl;
	return 0;
}