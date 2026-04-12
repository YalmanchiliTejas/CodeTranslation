#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {FIN
  	int a = 0, b = 0, i;
            string s;
            cin >> s;
            for (i == 0; i < s.size(); i++) {
            	if (s[i] == 'A')
                  	a++;
              else
                b++;
            }
            if (a == 3 or b == 3)
              	cout << "No\n";
           	else
              cout << "Yes\n";
	return 0;           
}