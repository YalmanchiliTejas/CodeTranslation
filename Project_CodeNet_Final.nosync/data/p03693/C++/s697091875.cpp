#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

//Code Short
#define REP(i,n) for(int i = 0;i < n;++i)
#define PB(s) push_back(s)
#define DSORT(n) sort(n.begin(),n.end())
#define QECHO(n) cout << n
#define QECHOS(n) cout << n << " "

//Define Math
const double EPS = 1e-10;
const double PI  = acos(-1.0);

using namespace std;
typedef long long ll;
/* prototype */
int EDSum(ll);//各桁の和
vector<int> SOE(int,int);//素数 (Min,Max)
int MinCM(int,int);//最小公倍数(num1,num2)
int MaxCD(int,int);//最大公約数(num1,num2)
vector<int> igets(int);//cin * N
ll nPr(ll,ll); //(n,r)
ll nE(ll); //(n)
ll nCr(ll,ll); //(n,r)

void solve(){
    //START
    int a,b,c;
    cin >> a >> b >> c;
    if((a*100+b*10+c)%4==0)cout << "YES" << endl; else cout << "NO" << endl;
}

int main(void){cin.tie(0);ios::sync_with_stdio(false);solve();}
int EDSum(ll number) {
  int ans = 0;
  while (1) {
    ans += number % 10;
    number /= 10;
    if (number == 0) break;
  }
  return ans;
}

vector < int > SOE(int min, int max) {
  if (min < 2) min = 2;
  vector < int > int_array;
  for (int i = min; i <= max; i++) int_array.push_back(i);
  vector < int > sosu;
  double stop = sqrt(max);
  while (true) {
    sosu.push_back(int_array.front());
    int_array.erase(int_array.begin());
    if (stop < (double)(sosu.back())) break;
    for (int i = 0; i < (int) int_array.size(); i++) {
      if (int_array[i] % sosu.back() == 0)
        int_array.erase(int_array.begin() + i);
    }
  }
  sosu.insert(sosu.end(), int_array.begin(), int_array.end());
  return sosu;
}

int MinCM(int a, int b) {
  int c = a * b;
  if (a < b)
    swap(a, b);
  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return c / b;
}

int MaxCD(int a, int b) {
  if (a < b)
    swap(a, b);
  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}
vector < int > igets(int N) {
  vector < int > A;
  int temp;
  for (int i = 0; i < N; ++i) {
    cin >> temp;
    A.push_back(temp);
  }
  return A;
}

ll nPr(ll n, ll r) {
  ll ans = 1;
  r = n - r;
  while (n != r) {
    ans *= n;
    --n;
  }
  return ans;
}

ll nE(ll n) {
  return nPr(n, n);
}

ll nCr(ll n, ll r) {
  if (r == 0) return -1;
  else {
    if (0 != n - r && n - r < r) r = n - r;
    return nPr(n, r) / nE(r);
  }
}