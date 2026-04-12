#include <iostream>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int main() {
  fast_io;

  string s;
  cin >> s;
  
  if (s == "AAA" || s == "BBB")
  	cout << "No" << endl;
  else 
  	cout << "Yes" << endl;
}