#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <limits.h>
#include <set>
#include <map>
#include <tuple>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,N) for (ll i=0;i<N;i++)
#define loop(i,N,M) for(ll i=N;i<M;i++)
#define MAX(v) *max_element(v.begin(),v.end())
#define MIN(v) *min_element(v.begin(),v.end())
#define SORTL2S(type,v) sort(v.begin(),v.end(),greater<type>())
#define SORTS2L(type,v) sort(v.begin(),v.end())
#define SORTMF(v,func) sort(v.begin(),v.end(),func)

template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

ll N;
vector<int> vec;

void solve() {

  int mn = 0;
  int ans=0;
  
  rep(i,N) {
    if (vec[i]>=mn) {
      ans++;
      mn = vec[i];
    }
  }
  
  cout << ans;
  	
	return;
}

int main() {

	cin >> N;
  vec.resize(N);
  rep(i,N) cin >> vec[i];

	solve();
	cout << endl;
	return 0;
}