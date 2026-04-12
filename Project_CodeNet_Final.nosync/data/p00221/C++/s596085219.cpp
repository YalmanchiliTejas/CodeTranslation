#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod 1e9+7

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int solve(string s) {
  int sum = 0;
  int num = 1;
  dep(i, s.length() - 1, 0) {
    sum += ((int)s[i] - 48) * num;
    num *= 10;
  }
  return sum;
}

int main() {
  int a, b;
  while(cin >> a >> b && a) {
    int aa[a];
    rep(i, 0, a) aa[i] = i + 1;
    aa[a - 1] = 0;
    int sum = 0;
    string s;
    int z = a - 1, i = 0;
    rep(j, 0, b) {
      sum++;
      cin >> s;
      if(!(sum % 5) && !(sum % 3)) {
        if(s == "FizzBuzz") {z = i; i = aa[i]; continue;}
      }else if(!(sum % 5)) {
        if(s == "Buzz") {z = i; i = aa[i]; continue;}
      }else if(!(sum % 3)) {
        if(s == "Fizz") {z = i; i = aa[i]; continue;}
      }else {
        if(s[0] >= '0' && s[0] <= '9') {
          if(sum == solve(s)) {z = i; i = aa[i]; continue;}
        }
      }
      if(aa[z] == aa[i]) {
        aa[0] = -3;
        break;
      }
      aa[z] = aa[i];
      i = aa[i];
    }
    while(1) {
      if(aa[i] <= i) {
        i = aa[i];
        break;
      }
      i = aa[i];
    }
    bool first = true;
    while(1) {
      if(aa[i] == -1) break;
      if(!first) cout << " ";
      first = false;
      cout << i + 1;
      int sum = aa[i];
      aa[i] = -1;
      i = sum;
    }
    cout << endl;
  }
}