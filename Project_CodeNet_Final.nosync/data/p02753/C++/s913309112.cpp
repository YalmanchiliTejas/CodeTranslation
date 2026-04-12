#include <bits/stdc++.h>

using namespace std;

class fastio {
public:
    fastio() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} __fastio;

int main(){
	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB")
	{
		cout << "No" << "\n";
	} else {
		cout << "Yes" << "\n";
	}
	return 0;
}
