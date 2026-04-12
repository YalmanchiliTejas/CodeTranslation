#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	string s; cin>>s; n--;
	map<char,int> x;
	for (char ch : s)
		x[ch]++;
	while(n-->0) {
		cin>>s;
		map<char,int> y;
		for (char ch : s)
			y[ch]++;
		for (char ch='a'; ch<='z'; ch++)
			x[ch]=min(x[ch],y[ch]);
	}
	for (char ch='a'; ch<='z'; ch++)
		while(x[ch]-->0)
			cout<<ch;
	cout<<"\n";
	return 0;
}