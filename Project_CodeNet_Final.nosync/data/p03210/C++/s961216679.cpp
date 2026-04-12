#include <iostream>

using namespace std;

int main(){

	ios::sync_with_stdio(false);

	int idade;

	cin >> idade;

	cout << (idade == 3 or idade == 5 or idade == 7 ? "YES" : "NO" ) << endl;

	return 0;
}