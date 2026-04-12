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
//#include <boost/foreach.hpp>
//#include <boost/range/algorithm.hpp>
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define ll long long
#define Sort(v) sort(all(v))
#define INF 1000000000
#define END return 0
#define pb push_back
#define se second
#define fi first
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define MP make_pair
//#define MOD 1000000007LL
#define int long long
using namespace std;
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

bool s(int n){
    int a=n%10;
    while(n){
        if(n%10!=a)return 0;
        n/=10;
    }
    return 1;
}

signed main (){
    vector<string> v;
    int h,w;cin>>h>>w;
    rep(i,0,h){
        string s;cin>>s;
        bool ok=true;
        rep(j,0,s.size()){
            if(s[j]=='#')ok=false;
        }
        if(!ok)v.push_back(s);
    }
    // rep(i,0,v.size()){
    //     rep(j,0,w)cout<<v[i][j];
    //     cout<<endl;
    // }
    vector<int> reject;
    rep(i,0,w){
        bool ok=true;
        rep(j,0,v.size()){
            if(v[j][i]=='#')ok=false;
        }
        if(!ok)reject.push_back(i);
    }
    rep(i,0,v.size()){
        rep(j,0,w){
            if(find(all(reject),j)!=reject.end())cout<<v[i][j];
        }
        cout<<endl;
    }


    
}
/*
1-21-2
*/
