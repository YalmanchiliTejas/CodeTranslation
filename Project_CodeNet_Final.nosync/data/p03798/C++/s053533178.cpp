#include <iostream>
using namespace std;

int to_int(char c) {
  if(c == 'o') {
    return 1;
  } else {
    return 0;
  }
}
char to_sw(int i) {
  if(i == 1) {
    return 'S';
  } else {
    return 'W';
  }
}
int main() {
  // string line = "ooxoox";
  // int N = 6;

  string s;
  int N;
  cin >> N;
  cin >> s;
  // getline(cin, line);
  int array[N];



  // ******************************
  array[0] = 1;
  array[1] = 1;

  for(int i = 2; i < N; i++) {
    array[i] = (array[i - 2] + array[i - 1] + to_int(s[i - 1])) % 2;
  }
  if ((array[0] + array[N - 2] + array[N - 1] + to_int(s[N - 1])) % 2 == 0 &&
      (array[0] + array[1] + array[N - 1] + to_int(s[0])) % 2 == 0
  ) {
    for (int i = 0; i < N; i++) {
      cout << to_sw(array[i]);
    }
    cout << endl;
    return 0;
  } else {
    // cout << -1 << endl;
  }
  // ******************************
  array[0] = 1;
  array[1] = 0;

  for(int i = 2; i < N; i++) {
    array[i] = (array[i - 2] + array[i - 1] + to_int(s[i - 1])) % 2;
  }
  if ((array[0] + array[N - 2] + array[N - 1] + to_int(s[N - 1])) % 2 == 0 &&
      (array[0] + array[1] + array[N - 1] + to_int(s[0])) % 2 == 0
  ) {
    for (int i = 0; i < N; i++) {
      cout << to_sw(array[i]);
    }
    cout << endl;
    return 0;
  } else {
    // cout << -1 << endl;
  }
  // ******************************
  array[0] = 0;
  array[1] = 1;

  for(int i = 2; i < N; i++) {
    array[i] = (array[i - 2] + array[i - 1] + to_int(s[i - 1])) % 2;
  }
  if ((array[0] + array[N - 2] + array[N - 1] + to_int(s[N - 1])) % 2 == 0 &&
      (array[0] + array[1] + array[N - 1] + to_int(s[0])) % 2 == 0
  ) {
    for (int i = 0; i < N; i++) {
      cout << to_sw(array[i]);
    }
    cout << endl;
    return 0;
  } else {
    // cout << -1 << endl;
  }
  // ******************************
  array[0] = 0;
  array[1] = 0;

  for(int i = 2; i < N; i++) {
    array[i] = (array[i - 2] + array[i - 1] + to_int(s[i - 1])) % 2;
  }
  if ((array[0] + array[N - 2] + array[N - 1] + to_int(s[N - 1])) % 2 == 0 &&
      (array[0] + array[1] + array[N - 1] + to_int(s[0])) % 2 == 0
  ) {
    for (int i = 0; i < N; i++) {
      cout << to_sw(array[i]);
    }
    cout << endl;
    return 0;
  } else {
    // cout << -1 << endl;
  }


  cout << -1 << endl;

  return 0;
}
