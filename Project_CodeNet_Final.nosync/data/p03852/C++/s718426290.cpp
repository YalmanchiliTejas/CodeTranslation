#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef string str;
typedef std::pair<ll,ll> pl;
typedef std::map<string, ll> msl;
typedef std::map<ll, ll> mll;
typedef std::vector<ll> vl;
const long double EPS = 1e-9;
 
#define rep(i, n) for(ll (i) = 0; (i) < (n) ; (i)++ )
#define For(i, a, b) for(ll (i) = (a); (i) < (b) ; (i)++ )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define tol(c) char((c)+0x20)
#define tou(c) char((c)-0x20)
#define pb push_back
#define mp make_pair
#define pr(a) cout << (a)
#define prl(a) cout << (a) << endl
#define prl2(a,b) cout << (a) << " " << (b) << endl
#define prs(a) cout << (a) << " "
#define yn(condition) if ((condition)) prl("Yes"); else prl("No");
#define YN(condition) if ((condition)) prl("YES"); else prl("NO");
#define rpr(i,n,ans) rep((i),(n)) prs((ans[(i)]))
#define cpr(i,n,ans) rep((i),(n)) prl((ans[(i)]))
#define in1(a) cin >> (a)
#define in2(a,b) cin >> (a) >> (b)
#define in3(a,b,c) cin >> (a) >> (b) >> (c)
#define in4(a,b,c,d) cin >> (a) >> (b) >> (c) >> (d)
#define rin1(i,n,a) rep((i),(n)) cin >> (a[(i)])
#define rin2(i,n,a,b) rep((i),(n)) cin >> (a[(i)]) >> (b[(i)])
#define rin3(i,n,a,b,c) rep((i),(n)) cin >> (a[(i)]) >> (b[(i)]) >> (c[(i)])
#define e1 first
#define e2 second
#define ctol(c) ll((c)) - ll('0')
#define ltos(n) to_string((n))
#define items(kv, v) for(auto &(kv): (v))
#define ndig(N, n) ctol(ll(ltos((N))[ll(ltos((N)).length()) - (n)]))
#define beto(a,b,c) (a) < (b) && (b) < (c)
#define betc(a,b,c) (a) <= (b) && (b) <= (c)
#define rsort(a,n) sort(a,a+n,greater<>())
 
const ll mod = 1e9 + 7;
const ll INF = mod * mod;
const ll MAX_N = 100;
 
int main(void){
    ll a,b;
    str s,op;

    in1(s);
    if (s[0] == 'a') prl("vowel");
    else if (s[0] == 'i') prl("vowel");
    else if (s[0] == 'u') prl("vowel");
    else if (s[0] == 'e') prl("vowel");
    else if (s[0] == 'o') prl("vowel");
    else prl("consonant");

    return 0;
}