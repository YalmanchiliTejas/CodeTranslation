#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
  	cin >> N;
  
  	int custom = 800 * N;
  	int num = N / 15;
  
  	cout << custom - num * 200 << endl;
}