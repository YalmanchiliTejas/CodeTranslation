#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <numeric>
#include <cstdlib>
#include <random>
#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
//typedef vector<ll> vec;
//typedef vector<vec> mat;

const ll mod=1000000007ll;
const ll inf=1000000000000000ll;


int main(){
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll ans;
  if(x>y) ans=min(a*x+b*y,min(2*c*y+(x-y)*a,2*max(x,y)*c));
  else ans=min(a*x+b*y,min(2*c*x+(y-x)*b,2*max(x,y)*c));
  cout<<ans<<endl;
}
