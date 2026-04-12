#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
	int N;
	cin >> N;
	int pay = N * 800;
	int income = (N / 15) * 200;
	cout << pay - income << endl;
}