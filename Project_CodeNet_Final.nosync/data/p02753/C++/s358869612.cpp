#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)
using namespace std;

string str;

int main(){ 
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> str;
	for(int i = 0; i < 3; i++)
		for(int j = i + 1; j < 3; j++)
			if(str[i] != str[j]){
				cout << "Yes\n";
				return 0;
			}
	cout << "No\n";
	return 0;
}

