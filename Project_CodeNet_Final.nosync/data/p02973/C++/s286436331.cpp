#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const int INF = 1000000007;

int N, A[100005];
multiset<int> st;

int main(void) {
  cin >> N;
  st.insert(INF);
  for(int i=0; i<N; i++) {
    int a; scanf("%d", &a);
    a *= -1;
    auto itr = st.upper_bound(a);
    if (*itr == INF) st.insert(a);
    else {st.erase(itr); st.insert(a);}
  }
  cout << st.size()-1 << endl;
  
  
    
    return 0;
}

