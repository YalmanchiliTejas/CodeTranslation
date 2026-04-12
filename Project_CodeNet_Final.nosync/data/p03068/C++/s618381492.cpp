#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

int main(){
  int N, K;
  string s;
  cin >> N >> s >> K;

  char ch = s[K-1];

  for(int i = 0; i < N; i++){
    if(s[i] != ch){
      s[i] = '*';
    }
  }

  cout << s << endl;
  return 0;
}
