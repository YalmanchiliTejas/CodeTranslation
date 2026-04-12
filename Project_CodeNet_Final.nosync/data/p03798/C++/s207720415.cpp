#include <iostream>
using namespace std;

string make_t(string s, string t);
string make_s(string t);

int main() {
  int n;
  string s;
  cin >> n >> s;
  string t[] = {"11", "01", "10", "00"}, result;
  int i;
  for (i = 0; i < 4; i++) {
    result = make_t(s, t[i]);
    result.erase(result.end() - 1);
    if (make_s(result) == s) {
      break;
    }
    if (i == 4 - 1) {
      result = "-1";
    }
  }
  for (i = 0; i < n; i++) {
    if (result == "-1") {
      break;
    }
    if (result.at(i) == '0') {
      result.at(i) = 'W';
    } else {
      result.at(i) = 'S';
    }
  }
  cout << result << endl;
  return 0;
}

string make_t(string s, string t) {
  int i;
  for (i = 1; i < s.length(); i++) {
    if (s.at(i) == 'o') {
      if (t.at(i) - '0') {
        t.push_back(t.at(i - 1));
      } else {
        t.push_back(t.at(i - 1) ^ 1);
      }
    } else {
      if (t.at(i) - '0') {
        t.push_back(t.at(i - 1) ^ 1);
      } else {
        t.push_back(t.at(i - 1));
      }
    }
  }
  return t;
}

string make_s(string t) {
  string result = "";
  if (t.at(1) == t.at(t.length() - 1) ^ t.at(0) - '0') {
    result.push_back('x');
  } else {
    result.push_back('o');
  }
  int i;
  for (i = 1; i < t.length() - 1; i++) {
    if (t.at(i - 1) == t.at(i + 1) ^ t.at(i) - '0') {
      result.push_back('x');
    } else {
      result.push_back('o');
    }
  }
  if (t.at(t.length() - 2) == t.at(0) ^ t.at(t.length() - 1) - '0') {
    result.push_back('x');
  } else {
    result.push_back('o');
  }
  return result;
}
