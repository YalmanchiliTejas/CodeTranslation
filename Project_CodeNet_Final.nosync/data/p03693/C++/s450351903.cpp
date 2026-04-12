#include<iostream>
using namespace std;
int a,b,c;
int main(){
	cin >> a >> b >> c;
	a=b*10+c;
	if(a%4==0){
		cout << "YES";
	}else{
		cout << "NO";
	}
}