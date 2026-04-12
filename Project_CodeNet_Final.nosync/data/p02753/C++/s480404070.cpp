#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin>>s;
	int aux = count(s.begin(), s.end(), 'A');
	if(aux == 0 || aux == 3)	cout<<"No\n";
	else	cout<<"Yes\n";
	return 0;
}