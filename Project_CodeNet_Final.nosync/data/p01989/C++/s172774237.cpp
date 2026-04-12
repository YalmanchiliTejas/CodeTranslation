#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

bool isValid(string s){
  if(s.size() == 1) return true;
  if(s[0] != '0' && stoi(s) <= 255) return true;
  return false;
}

int main(){
  string s;
  int ans = 0;
  
  cin >> s;

  for(int i=1;i<s.size();i++){
    for(int j=i+1;j<s.size();j++){
      for(int k=j+1;k<s.size();k++){
        // [0,i), [i,j), [j,k), [k,n)

        bool f = true;
        f &= isValid(s.substr(0,i));
        f &= isValid(s.substr(i,j-i));
        f &= isValid(s.substr(j,k-j));
        f &= isValid(s.substr(k,s.size()-k));        

        ans += f;
      }
    }
  }
  

  cout << ans << endl;
  
  
  return 0;
}

