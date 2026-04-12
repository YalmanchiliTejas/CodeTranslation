#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip>
 
using namespace std;
#define LOCAL  1
#define UPLOAD 2
#define ll long long
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
template <class T = long long> T input(){T x;cin >> x;return x;}
template <class T> void output(T x){cout << x << endl;}
#define debug(x) cerr << #x<< ": " << x<< '\n';
#define debugBit(x,n) cerr << #x<< ": " << std::bitset<n>(x) << '\n';
 
int main()
{
#if LOCAL_ENVIRONMENT == 1
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
  ll N = input();
  ll M = input();
 
  string reslt = N<=M ? "Yes" : "No";
  output(reslt);
 
  return 0;
}