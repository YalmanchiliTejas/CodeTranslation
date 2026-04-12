#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
string s="FESTIVAL";
string ans=s;
const ll b=200;
void solve(ll k, int i){
  for(int j=0; j<(k-1)%b; j++){
    ans+=s[i];
  }
  if((k-1)/b>0){
    solve((k-1)/b, i-1);
    for(int j=0; j<b; j++) ans+=s[i];
  }
}
int main()
{
  ll k;
  cin>>k;
  solve(k, 7);
  cout<<ans<<endl;
    return 0;
}