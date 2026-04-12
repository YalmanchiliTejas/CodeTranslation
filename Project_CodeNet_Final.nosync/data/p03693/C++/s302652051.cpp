#include<iostream>
using namespace std;
int main(){
	int n;
	int r,g,b;
	cin >> r >> g >> b;
	n=r*100+g*10+b;
	if(n%4==0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
