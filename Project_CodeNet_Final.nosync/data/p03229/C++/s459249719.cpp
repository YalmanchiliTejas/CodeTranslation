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
#include <cwchar>
#include <cwctype>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
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
#include <codecvt>
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
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long int ll;
typedef long double ld;
const ll INF=(1LL<<62);
const ld pi=acosl((ld)-1);
// const ll mod = 1000000007;
const ll mod = 1234567;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int ddx[8]={1,0,-1,-1,-1,0,1,1};
const int ddy[8]={1,1,1,0,-1,-1,-1,0};
#define endn "\n"

bool solve(){
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];


    ll ans=0;

    {
        multiset<ll>set;
        rep(i,n)set.insert(a[i]);
        deque<ll>v={*(--set.end())};
        set.erase(--set.end());
        for(int i=0;set.size()!=0;i++){
            if(i%4==0){
                v.push_front(*set.begin());
                set.erase(set.begin());
            }
            if(i%4==1){
                v.push_back(*set.begin());
                set.erase(set.begin());
            }
            if(i%4==2){
                v.push_front(*(--set.end()));
                set.erase(--set.end());
            }
            if(i%4==3){
                v.push_back(*(--set.end()));
                set.erase(--set.end());
            }
        }
        ll num=0;
        for(int i=0;i+1<v.size();i++)num+=abs(v[i+1]-v[i]);
        chmax(ans,num);
    }

    {
        multiset<ll>set;
        rep(i,n)set.insert(a[i]);
        deque<ll>v={*set.begin()};
        set.erase(set.begin());
        for(int i=0;set.size()!=0;i++){
            if(i%4==2){
                v.push_front(*set.begin());
                set.erase(set.begin());
            }
            if(i%4==3){
                v.push_back(*set.begin());
                set.erase(set.begin());
            }
            if(i%4==0){
                v.push_front(*(--set.end()));
                set.erase(--set.end());
            }
            if(i%4==1){
                v.push_back(*(--set.end()));
                set.erase(--set.end());
            }
        }
        ll num=0;
        for(int i=0;i+1<v.size();i++)num+=abs(v[i+1]-v[i]);
        chmax(ans,num);
    }

    cout<<ans<<endl;
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(30);
    solve();
}
