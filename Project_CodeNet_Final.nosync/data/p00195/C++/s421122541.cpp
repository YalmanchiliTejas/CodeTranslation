#include <iostream>

using namespace std;


int main() {

  int s1,s2;

  int max,max_id;


  while(cin >> s1 >> s2) {

    if(s1==0 && s2==0) break;

    max=s1+s2;
    
    max_id=0;

    for(int i=1;i<5;i++) {

      cin >> s1 >> s2;

      if(max<s1+s2) {

	max=s1+s2;

	max_id=i;

      }

    }

    cout << (char)('A'+max_id) << " " << max << endl;

  }

  return 0;

}