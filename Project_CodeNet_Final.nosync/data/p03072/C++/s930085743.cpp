#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int answer = 0;
  int n;
  
  cin >> n;
  
  int v[n];
  for (int i=0;i<n;++i) {
    cin >> v[i];
  }
  
  answer = 1;
  for (int i=1;i<n;++i) {
    bool check = true;
    for (int j=0;j<i;++j) {
        if (v[i] < v[j]) {
          check = false;
          break;
        }
    }

    if (check)
      answer++;
  }
    
  cout << answer << endl;

  return 0;
}
