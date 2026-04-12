#include<bits/stdc++.h>
using namespace std;
int main() {
  int s1, s2;
  while( cin >> s1 >> s2, s1+s2 ) {
    int maxn = s1 + s2;
    char maxi = 'A';
    for(int i=1; i<5; i++) {
      cin >> s1 >> s2;
      if( maxn < s1 + s2 ) {
	maxn = s1 + s2;
	maxi = 'A' + i;
      }
    }

    cout << maxi << ' ' << maxn << endl;
  }
}