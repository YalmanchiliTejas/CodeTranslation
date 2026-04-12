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
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define ll long long
#define all(v) ((v).begin(),(v).end())
#define Sort(v) sort(all(v))
#define INF 1000000000
#define END return 0
using namespace std;
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,0,n)cin>>v[i];
    
    //行き
    int pos=n-1;
    bool ok=false;
    for(int i=n-1;i>=0;i--){
        if((pos-i)*10<=v[i]){
            pos=i;
            if(i==0)ok=true;
        }
    }

    if(!ok){
        cout<<"no"<<endl;
        return 0;
    }

    //帰り
    pos=0;
    ok=false;
    rep(i,0,n){
        if((i-pos)*10<=v[i]){
            pos=i;
            if(i==n-1)ok=true;
        }
    }

    if(!ok){
        cout<<"no"<<endl;
        return 0;
    }
    cout<<"yes"<<endl;

    
    

}



    
