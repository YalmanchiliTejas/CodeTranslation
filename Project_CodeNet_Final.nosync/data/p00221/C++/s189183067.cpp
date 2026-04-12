#include<iostream>
#include<cstring>
#include<sstream>

using namespace std;

const int MAX = 1010;
bool fail[MAX];

bool isOK(const string& s, int n){
  if(n % 15 == 0) return s == "FizzBuzz";
  if(n % 5 == 0) return s == "Buzz";
  if(n % 3 == 0) return s == "Fizz";

  stringstream ss(s);
  int a;
  ss >> a;
  return a == n;
}

int main(){

  int m,n;
  while(cin >> m >> n && m+n){
    memset(fail,false,sizeof(fail));
    fail[0] = true;

    int rem = m;
    int player = 1;
    for(int i = 1; i <= n; i++){
      string s;
      cin >> s;
      if(rem == 1) continue;
      while(fail[player]) player = (player+1)%(m+1);
      if(!isOK(s,i)){
	fail[player] = true;
	rem--;
      }
       player = (player+1)%(m+1);
    }

    bool f = false;

    for(int i = 1; i <= m; i++){
      if(fail[i]) continue;
      if(f) cout << " ";
      cout << i;
      f = true;
    }
    cout << endl;
  }
  return 0;
}