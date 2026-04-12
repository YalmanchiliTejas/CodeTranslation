#include<iostream>
#include<string>
using namespace std;

int main(void){
	string r,g,b;
	int ans;
	cin >> r >> g >> b;
	string s = r+g+b;
	ans = stoi(s);
	if(!(ans%4)) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}