#include <bits/stdc++.h>
using namespace std;

int main(){
   	ios::sync_with_stdio(false);
	cin.tie(0);
    string s;
    int a = 0, b = 0;
	cin >> s;
	for (auto c : s){
        if (c == 'A') a+= 1;
        else b += 1;
    }
    if (a != 3 && b != 3) cout << "Yes";
    else cout << "No";
	return 0;
}