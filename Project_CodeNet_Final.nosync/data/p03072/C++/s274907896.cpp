#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv) {
  int N;
  cin >> N;
  int Hmax = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
  	int h;
    cin >> h;
    if (h >= Hmax) ans++;
    Hmax = max(Hmax, h);
  }
  cout << ans << endl;
}