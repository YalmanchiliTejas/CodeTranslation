#ifndef LOCAL
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#else
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#endif
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c>{i, j}; } sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; } eni(!=) cerr << boolalpha << i; ris; } eni(==) ris << range(begin(i), end(i)); } sim, class b dor(pair < b, c > d) { ris << "(" << d.first << ", " << d.second << ")"; } sim dor(rge<c> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]"; }
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define all(V) V.begin(), V.end()
#define rall(V) V.rbegin(), V.rend()
#define len(V) (int)V.size()
#define ll long long
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


int main() {
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int a = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == 'A') a++;
    }
    if (a == 0 or a == 3){
        cout << "No";
    } else {
        cout << "Yes";
    }
    

}
