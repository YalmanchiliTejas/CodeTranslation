#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
//#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef vector<long long> vll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template <class T> inline T gcd(T a, T b) {if(a==0) return b; return gcd(b%a,a);}
template <class T> inline T lcm(T a, T b) {return a * b / gcd(a,b);}
template <class T> inline T sum(vector<T> &vec) {T res=0; for (int i = 0; i < vec.size(); i++) res += vec[i]; return res;}
template <class T> inline T mpow(T a, T b) {if(b==0)return 1; T c = mpow(a,b/2);if(b%2==1)return c*c*a; return c*c;}
const int INF = 1 << 30;
const long long INFLL = 1LL << 60;
typedef pair<int, int> P;

#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define FOR(i,n) for (int (i)=0;(i)<(n);(i)++)
#define REPB(i,n) for (int (i)=((n)-1);(i)>=0;(i)--)
#define FORB(i,n) for (int (i)=((n)-1);(i)>=0;(i)--)
#define SORT(A) sort((A).begin(),(A).end())


int main() {
    int N,M; cin >> N >> M;
    if (N == M) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }


}
