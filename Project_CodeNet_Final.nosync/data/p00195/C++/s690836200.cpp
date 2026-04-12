#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  for(;;) {    
    pair<int,int> v[5];
    
    for(int i = 0; i < 5; i++) {
      int a, b;
      cin >> a >> b;
      if( a == 0 && b == 0 ) goto END;
      v[i] = make_pair(a + b, i);
    }
    sort( v, v + 5 );
    cout << (char)('A' + v[4].second) << " " << v[4].first << endl;
  }

 END:
  return 0;

}