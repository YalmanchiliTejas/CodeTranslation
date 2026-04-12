#include<iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	int ans;
	int test = N/15;
	ans = 800*N-200*test;
	cout << ans << endl;
	return 0;
}