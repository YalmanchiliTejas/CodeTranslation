#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;

int main(){
  char a[5]={'a','i','u','e','o'};
  string s;
  cin >> s;
  for (int i=0;i<5;i++){
	if (s.at(0)==a[i]){
      cout<<"vowel"<<endl;
      return 0;
    }
  }
  cout << "consonant" << endl;
  return 0;
}
