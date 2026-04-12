#include <iostream>

using namespace std;

void a() {
	int x;
	cin >> x;
	cout << ((x == 3 || x == 5 | x == 7) ? "YES" : "NO") << endl;
}

int main()
{
	a();
}

