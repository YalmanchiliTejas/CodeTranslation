#include <iostream>
using namespace std;
int main(void){
	int x,y,z;
	cin>>x>>y>>z;
	int sum = 0;
	sum = (x-z)/(y+z);
	if(sum == 0&&x/y>0){
		sum++;
	}
	cout<<sum<<endl;
}