#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	int x = 800*n;
	int y = 200*((int)n/15);
	cout<<x-y;
	return 0;
}
