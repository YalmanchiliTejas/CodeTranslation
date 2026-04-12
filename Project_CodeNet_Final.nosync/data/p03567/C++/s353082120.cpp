#include "bits/stdc++.h"

using namespace std;
static const int INF =(1<<21);


int main(){	
	string S;
	cin >> S;
	for(int i=0;i<3;i++)
		if (S[i] == 'A'&&S[i + 1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	cout << "No" << endl;
}