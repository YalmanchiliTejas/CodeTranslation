#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // long long64_t, long long*_t
#include <cstdio> // prlong longf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
using namespace std;
int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(a+b<2*c){
        cout << a*x+b*y << endl;
    }
    else{
      if(x==y){
        cout << c*2*x << endl;
      }
      else if(x>y){
        int a1,b1;
        a1=y*2*c+(x-y)*a;
        b1=y*2*c+(x-y)*2*c;
        cout << min(a1,b1) << endl;
      }
      else{
        int a1,b1;
        a1=x*2*c+(y-x)*b;
        b1=x*2*c+(y-x)*2*c;
        cout << min(a1,b1) << endl;
      }
    }
}
