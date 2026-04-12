#include"iostream"

using namespace std;

char S[3];

int main() {
	bool A = false, B = false;
	for (int i = 0; i < 3; i++) {
		cin >> S[i];
		if (S[i] == 'A')A = true;
		if (S[i] == 'B')B = true;
	}
	if (!A || !B) { cout << "No" << endl; }
	else { cout << "Yes" << endl; }
}