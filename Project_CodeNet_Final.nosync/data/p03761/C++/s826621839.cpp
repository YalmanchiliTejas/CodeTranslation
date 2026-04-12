#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> letters(27,-1);

	while (n--) {
		vector<int> l(27,-1);
		string s; cin>>s;
		for (char c : s) {
			if (l[c-'a']==-1) l[c-'a']=1;
			else l[c-'a']++;
		}
		for (int i=0; i<27; i++) {
			if (l[i]==-1) letters[i]=0;
			else if (letters[i]==-1) letters[i]=l[i];
			else letters[i] = min(letters[i],l[i]);
		}
	}

	for (int i=0; i<27; i++) {
		for (int j=0; j<letters[i]; j++) {
			cout << (char)(i+'a');
		}
	}

	cout << endl;
	return 0;
}