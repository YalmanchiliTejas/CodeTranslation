#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int N, T, E;
  int x;
  vector<int> vec_x;

  cin >> N >> T >> E;

  while (N--) {
    cin >> x;
    vec_x.push_back(x);
  }

  int i;
  bool isAldente = false;
  for (i = 0; i != vec_x.size(); i++) {
    for (int j = T - E; j <= T + E; j++) {
      if (!(j % vec_x.at(i))) {
        isAldente = true;
        break;
      }
    }
    if (isAldente) break;
  }

  isAldente ? cout << i + 1 << endl : cout << "-1" << endl;
}

