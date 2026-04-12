#include<iostream>
using namespace std;
int main(){
	int N,x,y;
	cin >> N;
	x=800*N;
	y=200*(N/15);
	cout << x-y << endl;
	return 0 ;
}