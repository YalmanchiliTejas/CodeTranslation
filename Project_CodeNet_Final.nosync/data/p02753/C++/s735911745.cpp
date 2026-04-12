// *****************************************************************
// *****************************************************************
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <stack>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
// *****************************************************************
// *****************************************************************
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fr(i,n) for(llu i=0;i<n;i++)
#define fl(j,a,b) for(llu j=a;j<=b;j++)
#define pi 3.14159265
#define mod 1e9+7
#define MID(a,b) ((a + b) >> 1)
#define MAX(a,b) ((a) > (b) ? (a): (b))
#define MIN(a,b) ((a) < (b) ? (a) :(b))
// *****************************************************************
// *****************************************************************
typedef long long unsigned int llu;
typedef long long int ll;
// *****************************************************************
// *****************************************************************
using namespace std;
// *****************************************************************
// *****************************************************************

       // I have no special talent. I am only passionately curious.

                         // tannatsri //

              // Without tact you can learn nothing.

// *****************************************************************
// *****************************************************************
template< class Iterator,  class T>
// template<typename TT>
// *****************************************************************
// *****************************************************************
Iterator search(Iterator start, Iterator end, T key) {
    while(start != end) {
        if(*start == key){
            return start;
        }
        ++start;
    }
    return end;
}
bool rev(int a, int b) {
    return a > b;
}
// *****************************************************************
// *****************************************************************
int main() {
    IOS;
    string s;
  	cin >> s;
  	set<char> ss;
  	for(auto i = s.begin();i != s.end(); ++i){
          ss.insert(*i);
      }
    if(ss.size() == 2) cout << "Yes\n";
    else cout <<"No" << "\n";
    return 0;
}