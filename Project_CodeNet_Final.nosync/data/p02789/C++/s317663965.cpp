#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <numeric>
#include <iomanip>
#include <deque>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define FOR(i, a, done) for (int i = (a); i < (done); ++i)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define x first
#define y second
#define pb push_back
#define pf push_front

namespace mp = boost::multiprecision;
using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;

ll M = 1000000007;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n==m){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}