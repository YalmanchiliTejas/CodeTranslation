#include <iostream>
#include <string>


using namespace std;


int main()
{
  int n, alpha[123]={50}, cnt;
  string s;

  for (int i=0; i<123; i++) alpha[i] = 50;

  cin >> n;
  for (int i=0; i<n; i++){
    cin >> s;
    for (int j='a'; j<='z'; j++){
      cnt = 0;
      for (int k=0; k<s.length(); k++){
	if (s[k] == (char)j){
	  cnt++;
	}
      }
      if (cnt < alpha[j]){
	alpha[j] = cnt;
      }
    }
  }

  for (int i='a'; i<='z'; i++){
    for (int j=0; j<alpha[i]; j++){
      cout << (char)i;
    }
  }
  cout << endl;
	  
  return 0;
}
