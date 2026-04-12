//#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<numeric>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<ctype.h>
#include <fstream>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;//int64
typedef unsigned long long ull;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}
int dy[4]={0,1,0,-1};
//----------program from here----------

int main(){
  int X=0;
  cin >> X;
  if((X==7)||(X==5)||(X==3)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}