#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  char a;
  cin >> a;
  if(a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o'){
    cout << "vowel" << endl;
  }
  else cout << "consonant" << endl;
  return 0;
}
