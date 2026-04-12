#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<limits>
#include<numeric>
#include<unordered_map>
#include<functional>
#include<bitset>
using namespace std;

#define rep(i,s,n) for(int i=s;i<n;i++)
#define dow(i,n,s) for(int i=n-1;i>=s;i--)
#define all(a) a.begin(),a.end()
#define Sort(a) sort(a.begin(),a.end())
#define rng(a,b,e) a.begin()+b,a.begin()+e
//#define DEBUG
typedef pair<int,int> II;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;
bool compare_by_second(II a,II b) {
  if(a.second != b.second) return a.second < b.second;
  else return a.first < b.first;
}
int compare_int(const void *a,const void *b){ return *(int *)a - *(int *)b; }

const int INF = 1e+9;
const int MAX_N = 5e+3;
const int MAX_V = 1e+9;

int n;
int a_i;
int d;
int sum,mx;
unordered_map<int, int> um;
//vector<int> v;

int main() {

  cin>>n;
  int v[n];
  //v.resize(n);
  mx = 2;
  rep(i,0,n) { cin>>v[i]; um[v[i]] = 1; }
  qsort(v,n,sizeof(*v),compare_int);
#ifdef DEBUG
  rep(i,0,n) cout<<v[i]<<" , ";
  cout<<endl;
#endif
  //Sort(v);
  rep(i,0,n-2) {
    rep(j,i+1,n-1) {
      d = v[j] - v[i];
      a_i = v[j] + d;
      sum = 2;
#ifdef DEBUG
      rep(k,j+1,n) {
        if(v[k] == a_i) { a_i += d; sum++; }
        if(v[k] > a_i) break;
      }
#endif
      rep(k,0,MAX_N-2) {
        if(um.find(a_i+d*k) == um.end() || k>=MAX_N-2) break;
        //cout<<k<<boolalpha<<num[k-1]<<" , ";
        sum++;
      }
      //cout<<endl;
      //mx = max(mx,sum);
      if(sum > mx) mx = sum;
      if(mx >= n-j-1) break;
    }
    if(mx >= n-i-1) break;
  }

  cout<<mx<<endl;
  return 0;
}

