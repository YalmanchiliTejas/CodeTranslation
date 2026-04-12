#include <bits/stdc++.h>
using namespace std;
// 298 round - 534 B
int main() {
	
	string s;
	cin>>s;
	
	if((s.find('A')==string::npos)||(s.find('B')==string::npos))
	    cout<<"No";
	else
	    cout<<"Yes";
	
	return 0;
}