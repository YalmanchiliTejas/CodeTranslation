#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9+7;

int main(){
  char s;
  cin >> s;

  if(s=='a') cout << "vowel" << endl;
  else if(s=='i') cout << "vowel" << endl;
  else if(s=='u') cout << "vowel" << endl;
  else if(s=='e') cout << "vowel" << endl;
  else if(s=='o') cout << "vowel" << endl;
  else cout << "consonant" << endl;

  return 0;
}
