#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <fstream>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<pii> vii;

#define INF 1000000007ll
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define Min(a,b) (((a) < (b))?(a):(b))
#define Max(a,b) (((a) > (b))?(a):(b))
#define Abs(a) (((a) > 0)?(a):(-1)*(a))
#define cil(a,b) ( ((a)%(b) == 0)?((a)/(b)):((a)/(b)+1) )
#define SIZE 0

int main() {
   int r, g, b;
   cin >> r >> g >> b;
   int t = r*100 + g*10 + b;
   if (t%4 == 0) cout << "YES" << endl;
   else cout << "NO" << endl;


   return 0;
}