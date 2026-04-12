#include <iostream>
using namespace std;

int main(){
	int N; cin >> N;
	int sum = N * 800;
	int disc = N / 15 * 200;
	cout << (sum - disc) << endl;
}