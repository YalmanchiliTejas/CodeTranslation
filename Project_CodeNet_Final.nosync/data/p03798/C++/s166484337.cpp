using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;
vector<int> v;


int main() {
  int N; cin >> N;
  string s; cin >> s;
  
  int tf[N], animal[N], prev[N], post[N];
  int f_animal[4] = {1, 1, -1, -1}, s_animal[4] = {1, -1, 1, -1};
  
  for (int i = 0; i < N; i++) {
    if (s[i] == 'o') tf[i] = 1;
    else tf[i] = -1;
    
    if (i == 0) prev[i] = N - 1;
    else prev[i] = i - 1;
    
    if (i == N - 1) post[i] = 0;
    else post[i] = i + 1;
  }
  
  for (int i = 0; i < 4; i++) {
    animal[0] = f_animal[i];
    animal[1] = s_animal[i];
    
    for (int j = 1; j < N; j++) {
      if (j == N - 1) {
        if (tf[N-1]*animal[N-2]*animal[N-1] == animal[0]) {
          if (tf[0]*animal[N-1]*animal[0] == animal[1]){
            for (int k = 0; k < N; k++) {
              if (animal[k] == 1) cout << 'S';
              else cout << 'W';
            }
            cout << endl;
            return 0;
          }
        }
      }
      animal[post[j]] = tf[j] * animal[prev[j]] * animal[j];
    }
  }
  cout << -1 << endl;
  return 0;
}