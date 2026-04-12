#include "bits/stdc++.h"

using namespace std;
// jebote stupidast
int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s[0] != s[2])cout << "Yes";
    else cout << "No";


	return 0;

}
