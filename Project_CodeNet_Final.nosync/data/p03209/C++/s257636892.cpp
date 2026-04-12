#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <iterator>
#define r(i,n) for(int i=0;i<n;i++)
#define R(i,c,n) for(int i=c;i<n;i++)
#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back
using namespace std;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

long long int ncount = 0;
long long int pcount = 0;
long long int n,x;
long long int pmemo[51] = {0};//countp
long long int lmemo[51] = {0};//length

void burger(int lv){
  // cout << lv << endl;
  if(pmemo[lv]!=0) return;
  burger(lv-1);
  pmemo[lv] = pmemo[lv-1]*2 + 1;
  lmemo[lv] = lmemo[lv-1]*2 + 3;
  return;
}

void countP(int lv) {
  if(ncount>=x) return;
  if (lmemo[lv] > x - ncount) {
    ncount ++;//B
    if(ncount>=x) return;
    countP(lv-1);
    if(ncount>=x) return;
    ncount ++;pcount ++;//P
    if(ncount>=x) return;
    countP(lv-1);
    ncount ++;//B
    if(ncount>=x) return;
  }else{
    pcount += pmemo[lv];//Lv
    ncount += lmemo[lv];
  }
}

int main(){
  ios::sync_with_stdio(false);
	cin.tie(0);
  pmemo[0] = 1;
  lmemo[0] = 1;
  cin >> n >> x;
  burger(n);
  countP(n);
  // cout << pmemo[n] << endl;
  // cout << lmemo[n] << endl;
  cout << pcount << endl;
  return 0;
}