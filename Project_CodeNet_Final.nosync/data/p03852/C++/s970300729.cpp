#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

int main(){
  
  char c;
  cin >> c;
  bool sub1 = c == 'a';
  bool sub2 = c == 'e';
  bool sub3 = c == 'i';
  bool sub4 = c == 'o';
  bool sub5 = c == 'u';
  if(sub1 || sub2 || sub3 || sub4 || sub5) cout << "vowel" << endl;
  else cout << "consonant" << endl;
  
}