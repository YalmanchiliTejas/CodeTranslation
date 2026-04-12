#include <iostream>
using namespace std;
int main(){
	int r, g, b;
	cin >> r >> g >> b ;
	int tmp;
	tmp = (100*r+10*g+b)%4;
	if(tmp==0){
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
