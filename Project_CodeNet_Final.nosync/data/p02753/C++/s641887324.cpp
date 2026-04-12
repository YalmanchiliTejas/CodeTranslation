#include<stack>
#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;(int) (n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s=="AAA" || s=="BBB") cout << "No" << endl;
  else cout << "Yes" << endl;
}