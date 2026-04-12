#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6+100;


int main()
{
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );

	string s;
	cin >> s;
	if(s.find("AC")!= s.npos ){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;

	return 0;
}
