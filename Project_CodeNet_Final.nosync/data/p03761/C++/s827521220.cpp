//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=200003;
int main(){
  int n;
  cin>>n;
  int c1[40],c2[40];
  fill(c1,c1+40,10000);
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    fill(c2,c2+40,0);
    for(int j=0;j<s.size();j++){
      c2[(int)s[j]-97]++;
    }
    for(int j=0;j<40;j++){
      c1[j]=min(c1[j],c2[j]);
    }
  }
  for(int i=0;i<40;i++){
    for(int j=0;j<c1[i];j++){
      cout<<(char)(i+97);
    }
  }
  cout<<endl;
  return 0;
}
