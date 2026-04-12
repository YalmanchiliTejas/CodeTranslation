#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
string s;
map<char,int> dic;
void solve(){
  cin >> n;
  for(char c='a';c<='z';c++){
    dic[c]=55;
  }
  for(int i=0;i<n;i++){
    cin >> s;
    for(char c='a';c<='z';c++){
      int cnt=count(s.begin(),s.end(),c);
      dic[c]=min(dic[c],cnt);
    }
  }
  for(char c='a';c<='z';c++){
    if(dic[c]>0){
      for(int i=0;i<dic[c];i++)cout << c;
    }
  }
  cout << endl;

}

int main(int argc, char *argv[]) {
  solve();
  return 0;
}
