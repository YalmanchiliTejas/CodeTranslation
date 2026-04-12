#include <iostream>
using namespace std;

int main() {
	int N;
	cin >>N;
	cout<<-200*((N-N%15)/15)+800*N;
	return 0;
}