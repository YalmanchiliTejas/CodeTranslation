#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define mod 1000000007 //1e9+7
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100

string r = "yuiophjklnm";

void calc(string s){

  bool last = false;
  int ans = 0;
  
  for(int i=0;i<11;i++) last |= s[0]==r[i];
  
  for(int i=1;i<s.size();i++){
    bool f = false;

    for(int j=0;j<11;j++) f |= s[i]==r[j];

    if(f ^ last){
      ans++;
      last = f;
    }
  }

  printf("%d\n",ans);
  
  return;
}

int main(){
  string s;
  
  while(1){
    cin >> s;
    
    if(s=="#") break;
    
    calc(s);
  }

  return 0;
}