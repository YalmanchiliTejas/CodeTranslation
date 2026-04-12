#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
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

// o(╥﹏╥)o

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

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

#if __cplusplus >= 201103L
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
#endif


using namespace std;

#define ld long double
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpll vector < pair<long long,long long> >
#define fill(a,val)  memset(a,val, sizeof (a))
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define mp make_pair
#define pb push_back
#define f first
#define se second
#define all(cont) cont.begin(), cont.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MAX   1e9
#define MIN  -1e9
typedef map<int,int> mpi;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef priority_queue<int> pq;
typedef tuple< int , int, int > tup;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i, n)    for(long long int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define repn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define PI 3.14159265

#define mod 1000000007

struct node{
    ll val;
};

struct Interval {int start, end;};
bool compare(struct node n1, struct node n2) {
    return (n1.val < n2.val);
}

const ll INF = 1e15+3;
const ll inf = 1e11+5;
const ll maxn = 1e6+2;


int main()
{
//    ll t; cin>>t;
//    while(t--)
//    {
    ll n; cin>>n; ll a[n]; rep(i,n)cin>>a[i];
    multiset <ll> s;
    s.insert(a[0]);
    repA(i,1,n-1)
    {
//        for(auto it=s.begin();it!=s.end();++it)
//            cout<<*it<<" ";
        
        //cout<<endl;
        auto itr = s.lower_bound(a[i]);
        if(itr==s.end())
            --itr;
        while(itr!=s.begin())
        {
            if(*itr < a[i])
                break;
            else
                itr--;
        }
        if(*itr<a[i])
        {
            s.erase(itr);
            s.insert(a[i]);
            continue;
        }
        else
            s.insert(a[i]);
    }
    cout<<s.size();
    //}
    return 0;
}
