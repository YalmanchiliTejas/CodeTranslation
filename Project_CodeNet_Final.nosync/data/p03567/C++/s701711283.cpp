#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 45;



int main() {
#ifdef suiyuan2009
  freopen("in.cpp","r",stdin);
#endif // suiyuan2009
  string s;
  cin>>s;
  bool sign=0;
  for(int i=0;i+1<s.size(); i++)
    if(s[i]=='A'&&s[i+1]=='C') {
      sign=1;
      break;
    }
  if(sign)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}

