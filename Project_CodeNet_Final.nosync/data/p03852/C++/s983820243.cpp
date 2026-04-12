#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n;
  char s;
  cin >> s;
  if (s=='a' || s=='i'|| s=='e'|| s=='o'|| s=='u') cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0; 
}
