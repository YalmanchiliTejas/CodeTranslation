#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	int r,g,b;
	cin >> r >> g >> b;
	if((100 * r + 10 * g + b) % 4 == 0)	cout << "YES\n" << endl;
	else puts("NO\n");
}