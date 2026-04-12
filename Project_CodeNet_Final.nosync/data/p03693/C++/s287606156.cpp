#include<iomanip>
#include<algorithm>

// from iostream
#include<iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::flush;
using std::endl;
// from vector
#include<vector>
using std::vector;
// from queue
#include<queue>
using std::deque;
using std::priority_queue;
// from tuple
using std::tuple;
using std::get;
using std::tie;
using std::make_tuple;
using std::forward_as_tuple;
// from string
#include<string>
using std::string;

typedef signed long long INT;
typedef tuple<INT,INT> TII;
typedef tuple<INT,INT,INT> TIII;
typedef tuple<double,double> TDD;
typedef tuple<double,double,double> TDDD;
typedef vector<INT>  VI;
typedef vector<TII>  VII;
typedef vector<TIII> VIII;
typedef vector<double> VD;
typedef vector<TDD>    VDD;
typedef vector<TDDD>   VDDD;

int main(){
  std::ios::sync_with_stdio(false);
  // begin main
  string yes = "YES",no="NO";
  INT r,g,b;
  cin >> r >> g >> b;
  INT sum = r*100 + g*10 + b;
  cout << ( sum%4 ? no : yes ) << endl;
  // end main
  return 0;
}
