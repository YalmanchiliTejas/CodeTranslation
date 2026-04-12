#include <bits/stdc++.h>
using namespace std;
#define make_pair mp
typedef long long int ll;
typedef unsigned long long int ull;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++){
		if (s[i] == 'A')
			a++;
		else
			b++;
	}
	if (a * b == 0){
		cout << "No";
	}
	else {
		cout << "Yes";
	}
	return 0;
} 