#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

  string in;
  cin >> in;

  long long int a;
  cin >> a;

  long long int k = 0;
  char c = '+';
  long long int n = 1;
  long long int ans_0 = 0;
  long long int ans_1 = 0;

  for ( long long int i = 0; i < in.size(); i++ ) {

    if ( in[i] == '+' ) {

      if ( c == '+' ) {
	ans_0 += k;
      }else {
	ans_0 *= k;
      }
      c = '+';
      n *= k;
      ans_1 += n;
      k = 0;
      n = 1;

    }else if ( in[i] == '*' ) {

      if ( c == '+' ) {
	ans_0 += k;
      }else {
	ans_0 *= k;
      }
      c = '*';
      n *= k;
      k = 0;

    }else {

      k = k * 10 + in[i] - '0';

    }

  }

  if ( c == '+' ) {
    ans_0 += k;
  }else {
    ans_0 *= k;
  }
  n *= k;
  ans_1 += n;

  string s = "ILMU";

  k = 0;

  if ( a == ans_0 ) k++;
  if ( a == ans_1 ) k += 2;

  cout << s[k] << endl;

  return 0;

}