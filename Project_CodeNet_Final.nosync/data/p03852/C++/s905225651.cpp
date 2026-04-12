#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
  char c;
  cin >> c;
  if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o')
    cout << "vowel" << endl;
  else
    cout << "consonant" << endl;
  return 0;
}