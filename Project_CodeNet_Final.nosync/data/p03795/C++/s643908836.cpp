#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = N / 15;
	
	cout << N * 800 - count * 200<<endl;
}