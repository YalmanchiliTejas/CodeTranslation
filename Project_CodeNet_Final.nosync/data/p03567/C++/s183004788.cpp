#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main() {
	string s;
	cin >> s;
	int t = s.find("AC");
	if (t == string::npos)  cout << "No" ;
	else cout << "Yes";
	
}