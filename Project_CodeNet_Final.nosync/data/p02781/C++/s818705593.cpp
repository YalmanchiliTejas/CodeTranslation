#include<stdio.h>
#include<iostream>
#include<algorithm> // sort(ALL())
#include<string>
#include<string> // to_string()
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue> // push(), front(), pop() 先入れ先出し
#include<map> // 連想配列 map<string, int>
#include<iomanip>
#include<set>
#include<utility>
using namespace std;
#define FOR(i, a, b) for(int i=(a); i<(b);  i++)
#define REP(i, n)    for(int i=0;   i<(n);  i++)
#define REP1(i, n)   for(int i=1;   i<=(n); i++)
#define pb push_back
#define mp make_pair
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define EPS 1e-7
#define ALL(obj) (obj).begin(), (obj).end()
using ul    = unsigned long;
using ll    = long long;
using ld    = long double;
using vint  = vector<int>;
using vll   = vector<ll>;
using pint  = pair<int, int>;
using pll   = pair<ll, ll>;
using vpint = vector<pint>;
using vpll  = vector<pll>;
const int INF = (int)1e9 + 1;
const int MOD = (int)1e9 + 7;
#define INT(argu) (int)(argu+EPS)



int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string n;
  int k;
  scan(n); scan(k);
  int di = n.length();
  vint lab;

  vint p;
  REP(i, di){
    if(n[i] != '0'){
      p.push_back( n[i] - '0' ); // n[0]=p[0], n[i]=x, n[j]=y
      lab.push_back( i ); // 0, i, j
      if(p.size()==3) break;
    }
  }
  int num = lab.size(); // 1 or 2 or 3

  if(di<k || ( di<=3 && atoi(n.c_str())<111 && k==3 ) ){
    cout << "0" << endl;
    return 0;
  }

  if(k==1){
    cout << (di-1)*9 // 0 [x0..0]
          + p[0] // x 0..0
         << endl; //
  }else if(k==2){
    if(num>=2){
      cout << (di-1)*(di-2)/2*9*9 // 0 [xy0...0]
            + (p[0]-1)*(di-1)*9 // x [y0...0]
            + (di-lab[1]-1)*9 // p[0] 0..0 0 [x0..0]
            +  p[1] // p[0] 0...0 x 0...0
            << endl;
    }else if(num==1){
      cout << (di-1)*(di-2)/2*9*9 // 0 [xy0...0]
            + (p[0]-1)*(di-1)*9 // x [y0...0]
            << endl;
    }
  }else if(k==3){
    if(num>=3){
      cout << (di-1)*(di-2)*(di-3)/6*9*9*9 // 0[xyz0...0]
            + (p[0]-1)*(di-1)*(di-2)/2*9*9 // x[yz0...0]
            + (p[1]-1)*(di-lab[1]-1)*9 // p[0] 0..0 x[y0...0]
            + (di-lab[1]-1)*(di-lab[1]-2)/2*9*9 // p[0] 0..0 0 [xy0..0]
            + p[2] // p[0] 0..0 p[1] 0..0 x 0..0
            + (di-lab[2]-1)*9 // p[0] 0..0 p[1] 0..0 0 [x0..0]
           << endl;
    }else if(num==2){
      cout << (di-1)*(di-2)*(di-3)/6*9*9*9 // 0[xyz0...0]
            + (p[0]-1)*(di-1)*(di-2)/2*9*9 // x[yz0...0]
            + (p[1]-1)*(di-lab[1]-1)*9 // p[0] 0..0 x [y0...0]
            + (di-lab[1]-1)*(di-lab[1]-2)/2*9*9 // p[0] 0..0 0 [xy0..0]
           << endl;
    }else if(num==1){
      cout << (di-1)*(di-2)*(di-3)/6*9*9*9 // 0[xyz0...0]
            + (p[0]-1)*(di-1)*(di-2)/2*9*9 // x[yz0...0]
           << endl;
    }
  }

//  REP(i, (int)(p.size()) ){
//    cout << p[i] << "\t" << lab[i] << endl;
//  }
//  cout << fixed << setprecision(10) <<  << endl;

  return 0;
}
