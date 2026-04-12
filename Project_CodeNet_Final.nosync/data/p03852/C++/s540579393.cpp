#include<iostream>
#include<string>
#include<string>
using namespace std;

#define ll long long
#define vecint vector<int>
#define listint list<int>

#define REP(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define print(a) cout << a << endl

#define MOD 1000000007;


int main(){
  char c;
  char list[]={'a','i','u','e','o'};
  cin >> c;
  string ans="consonant";
  rep(i,5){
    if(list[i]==c) ans="vowel";
  }
  print(ans);
  return 0;
}
