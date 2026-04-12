#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
  while(true){
    long n;
    cin >> n;
    if(n == 0){
      break;
    }
    vector<long> S;
    for(int i = 0; i < n;++i){
      long s;
      cin >> s;
      S.push_back(s);
    }
      long mx = *max_element(S.begin(), S.end());
      long mn = *min_element(S.begin(), S.end());
      long sum = accumulate(S.begin(), S.end(), 0);
      cout << (sum - mx - mn) / (n - 2)  << endl;
  }
 return 0;
}

