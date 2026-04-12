#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char a[5];
	cin>>a;
	for(int i=0; i<5; i++){
		if(a[i]==65 && a[i+1]==67){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}