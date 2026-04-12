#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
  	string s;
  	char a;
 	cin >> n >> s >> k;
  	a = s.at(k-1);
  	for (int i=0;i<n;i++) {
      if (s.at(i) == a) {
        continue;
      } else {
        
        s.at(i) = '*';
      }
    }
    cout << s << endl;
  	
}