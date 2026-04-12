#include <iostream>

using namespace std;

int main(){
	int casos,aprobados;
	cin>>casos>>aprobados;

	if (casos == aprobados){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}