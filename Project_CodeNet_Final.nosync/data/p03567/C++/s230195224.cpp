#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	for (int i=0;i+1<(int)s.size();i++){
		if (s[i]=='A'&&s[i+1]=='C') {
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}