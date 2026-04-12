#include<iostream>
#include<string>
#include<cstdint>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	if (n == m){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}