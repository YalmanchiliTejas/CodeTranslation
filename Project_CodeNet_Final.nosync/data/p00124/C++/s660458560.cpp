#include <iostream>
#include <string>
using namespace std;

void sort(string s[], int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (a[j - 1] < a[j]) {
	int t = a[j - 1];
	a[j - 1] = a[j];
	a[j] = t;
	string u = s[j - 1];
	s[j - 1] = s[j];
	s[j] = u;
      }
    }
  }
}

int main() {
  bool flag = false;
  for ( ; ; ) {
    int n;
    cin >> n;
    if (n == 0) return 0;
    if (flag) cout << endl;
    else flag = true;
    string s[n];
    int w[n], l[n], d[n], score[n];
    for (int j = 0; j < n; j++)
      cin >> s[j] >> w[j] >> l[j] >> d[j];
    for (int j = 0; j < n; j++)
      score[j] = w[j] * 3 + d[j];
    
    sort(s, score, n);
    for (int j = 0; j < n; j++)
      cout << s[j] << ',' << score[j] << endl;
  }
}