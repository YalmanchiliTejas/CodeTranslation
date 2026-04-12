//#include <bits/stdc++.h>
#include<iostream>
#include<climits>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include <string>
#include <complex>
#include <functional>
#include <map>
#include <queue>
#include <cctype>
#include <fstream>   // ifstream, ofstream
#include <sstream>   // istringstream
using namespace std;
using ll = long long;
const int mod = 1000000007;

ll gcd(ll a, ll b){return b ? gcd(b,a%b) : a;};//最大公約数
ll lcm(ll a, ll b){return a*b/gcd(a,b);};//最小公倍数
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//typedef pair<string,string> P;
//double dat[100][100];
//int dp[6][1010];//動的計画法
//int prime[100001];
//char str[1010][1010];
typedef pair<string,ll> A;
//vector<A> pc;
//int ABS(int a){return max(a,-a);}
//ll a[100000];
//ll dom[100001];

int main(){
  string s;
  int a=0,b=0;
  cin>>s;
  for(int i=0;i<3;i++){
    if(s[i]=='A') a++;
    else b++;
  }
  if(a==3||b==3) cout<<"No";
  else cout<<"Yes";
  return 0;
}