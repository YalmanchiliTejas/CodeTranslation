#include<bits/stdc++.h>
using namespace std;


int main()
{
  vector< int > sum(5);

  while(true) {
    for(int i = 0; i < 5; i++) {
      int s1, s2;
      if(cin >> s1 >> s2) {
        sum[i] = s1 + s2;
      } else {
        return(0);
      }
    }
    cout << (char)(max_element(sum.begin(), sum.end()) - sum.begin() + 'A') << " " << *max_element(sum.begin(), sum.end()) << endl;
  }
}