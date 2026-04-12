#include<iostream>
using namespace std;
int main(){
	char arr[3];
	int i = 3, temp_a=0, temp_b=0;
	cin>>arr;
	for(i=0; i<3; i++){
		if(arr[i]=='A') temp_a=1; 
		if(arr[i]=='B') temp_b=1;
	}
	if(temp_a==1&&temp_b==1)cout<<"Yes";
	else cout<<"No";
}