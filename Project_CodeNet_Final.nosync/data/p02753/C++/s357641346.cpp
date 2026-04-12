#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int main()
{
	string a;
	cin>>a;
	set<char>s;
	for(auto i:a){
		s.insert(i);
	}
	cout<<(s.size()==2?"Yes":"No");
}