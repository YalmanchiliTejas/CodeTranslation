#include <iostream>
#include <vector>

using namespace std;

int main() {
  for (;;) {
    int n;
    cin >> n;
    if (!n) return 0;
    int r = 0;
    vector<int> sequences;
    sequences.push_back(1);
    cin >> r;
    for (int i = 2; i <= n; i++) {
      int c;
      cin >> c;
      if (r == c)
        ++sequences[sequences.size()-1];
      else {
        r = c;
        if (i % 2)
          sequences.push_back(1);
        else {
          if (sequences.size() == 1)
            ++sequences[sequences.size()-1];
          else {
            sequences[sequences.size()-2] += sequences[sequences.size()-1] + 1;
            sequences.pop_back();
          }
        }
      }
      /*
      if (i % 2)
        if (r == c)
          ++sequences[sequences.size()-1];
        else {
          sequences.push_back(1);
          r = c;
        }
      else
        if (r == c)
          ++sequences[sequences.size()-1];
        else {
          sequences[sequences.size()-2] += sequences[sequences.size()-1] + 1;
          sequences.pop_back();
          r = c;
        }
      */
    }
    /*
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      if (r == c)
        ++sequences[sequences.size()-1];
      else {
        r = c;
        if (i % 2)
          ++sequences[sequences.size()-1];
        else
          sequences.push_back(1);
      }
    }
    */
    int count = 0;
    for (int i = 0; i < sequences.size(); i++)
      if (r && i % 2 || !r && !(i % 2))
        count += sequences[sequences.size()-i-1];
    cout << count << endl;
  }
}