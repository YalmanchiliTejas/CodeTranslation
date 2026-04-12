#include <iostream>
#include <climits>

using namespace std;

int main() {
    int x = INT_MIN;
    cin >> x;
    if (x >= 30) {
	cout << "Yes\n";
    } else {
	cout << "No\n";
    }
}
