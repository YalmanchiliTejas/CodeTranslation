#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define FOR(i, a, b) for (int i = a; i <= (int)(b); i++)
#define FORD(i, a, b) for (int i = a; i >= (int)(b); i--)
 
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))
using Lint = long long;
#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法
 
#define ALL(x) (x).begin(), (x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
 
#define PB push_back
#define MP make_pair
using P=pair<int, int>;
using V=vector<double>;
using M=map<int, int>;
using S=set<int>;
#include <math.h>
#define COUT(x) cout << (x) << endl
#define SCOUT(x) cout << (x) << " "
 
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
template <class T>bool chmax(T &a, const T &b){if (a < b){a = b;return 1;}return 0;}
template <class T>bool chmin(T &a, const T &b){if (b < a){a = b;return 1;}return 0;}
/* vector<T>のイテレータはvector<T>::iterator型
vector<int>::iterator it = vc.begin();  // begin()はvectorの最初の要素を指すイテレータを返す
vector<int>::iterator endIt = vc.end(); // end()はvectorの終端位置を指すイテレータを返す
while (it != endIt)
{
  cout << *it << '\n'; // イテレータの指す要素は、ポインタのように*演算子でアクセス
  it++;                // インクリメントすることで次の要素を指します。
}
}*/
int main(){
int n;
cin >> n;
  if(n>=30)COUT("Yes");
  else COUT("No");
  
}