#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

#define INF 1000000000

char l[20];
int idx;

int term(){
  int ret=l[idx++] - '0';
  while(l[idx]=='*'){
    idx++;
    ret *= l[idx++] - '0';
  }
  return ret;
}

int m_eval(){
  idx=0;
  int ret=term();
  while(l[idx] != '\0'){
    idx++; // skip '+'
    ret += term();
  }
  return ret;
}

int l_eval(){
  int ret=0;
  idx=0;
  while(l[idx]!='\0'){
    if(l[idx] == '+'){
      idx++;
    } else if(l[idx] == '*'){
      idx++;
      ret *= l[idx++] - '0';
    } else {
      ret += l[idx++] - '0';
    }
  }
  return ret;
}

int main(){
  int bob;
  scanf("%s\n%d", l, &bob);

  idx=0;
  int m = m_eval();
  int l = l_eval();

  if(bob==m && bob==l){
    cout << "U" << endl;
  } else if(bob==m && bob!=l){
    cout << "M" << endl;
  } else if(bob==l){
    cout << "L" << endl;
  } else {
    cout << "I" << endl;
  }

  return 0;
}