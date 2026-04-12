#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define f(i, n) for(int i = 0; i < n; ++i)
#define pb push_back
#define eb emplace_back
#define m_p make_pair
#define T int t = 0; cin >> t; while(t--)
#define pr(a) for(int i = 0; i < (int)a.size(); ++i)cout << a[i] << " ";cout << endl;
#define b_e(a) a.begin(), a.end()
typedef long long ll;
typedef long double lld;
const ll mod = 1e15;
const ll mx = 2e5;
const ll inf = 1e9;
const int sz = 26;
typedef long long ll;


void input(){
    IOS;
    int x;
    cin >> x;
    if(x >= 30)cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    input();
    return 0;
} 
/*
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
*/