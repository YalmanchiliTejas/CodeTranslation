#include <iostream>
using namespace std;

int main()
{
  int N, M;
  string A;
    cin >> N >> M;
    if (N == M) {
      A = "Yes";
    } else {
      A = "No";
    }
    cout << A << endl;
}
