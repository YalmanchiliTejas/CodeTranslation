#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	int a = 0, b = 0;
	for(auto ch : s){
		if(ch == 'A')a++;
		else b++;
	}
	if(a && b)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}