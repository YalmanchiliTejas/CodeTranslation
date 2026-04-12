#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int x,y,z;

int main(){
	cin>>x>>y>>z;
	int a=0;
	while(1){
		a++;
		if(y*a+z*(a+1)>x) {
			a--;
			break;
		}
	}
	cout<<a<<endl;
	return 0;
}