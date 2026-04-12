#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int K,A,B;
	cin >> K >> A >> B;
	if(A >= K){
		cout << 1 << endl;
		return 0;
	}
	if(A <= B){
		cout << -1 << endl;
		return 0;
	}
	cout << ((K - A - 1) / (A - B) + 1) * 2 + 1 << endl;
	return 0;
}
