// #define STOPIT
#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

void debug_impl() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail) { cerr << " " << head; debug_impl(tail...); }
#ifndef STOPIT
    #define debug(...)\
    do {\
        cerr << boolalpha << "[" << #__VA_ARGS__ << "]:";\
        debug_impl(__VA_ARGS__);\
        cerr << std::noboolalpha;\
    } while (false)
#else
    #define debug(...) {}
#endif

template < typename Container, typename Value = typename Container::value_type, enable_if_t<!is_same< Container, string >::value, nullptr_t> = nullptr>
istream& operator>> (istream& is, Container& v)
  { for (auto & x : v) { is >> x; } return is; }

template < typename Container, typename Value = typename Container::value_type, enable_if_t<!is_same< Container, string >::value, nullptr_t> = nullptr >
ostream& operator<< (ostream& os, Container const& v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); it++)
    {os << (it != v.begin() ? "," : "") << *it;}
  return os << "}";
}
int main()
{
    int N, M;
    cin >> N>> M;
    if (N==M)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
