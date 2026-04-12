#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	int n, f=0;

	while(cin >> n, n!=0) {
		if(!f) {
			f=1;
		}
		else {
			cout << endl;
		}
		multimap<int, string, greater<int> > team;
		for(int i=0; i<n; i++) {
			int a, b, c;
			char s[32];
			cin >> s >> a >> b >> c;
			team.insert(map<int, string>::value_type((3*a+c), s));
		}
		
		multimap<int, string, greater<int> >::iterator it=team.begin();
		while(it!=team.end()) {
			cout << it->second << "," << it->first << endl;
			it++;
		}
		team. clear();
	}

	return 0;

}