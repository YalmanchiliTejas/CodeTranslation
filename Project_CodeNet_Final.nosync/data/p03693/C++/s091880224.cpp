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

int ctoi(int x){
  return int(x-48);
}

int main(){
  int r=0,g=0,b=0,num=0;
  cin >> r >> g >> b;
  num = ctoi(r)*100 + ctoi(g)*10 + ctoi(b);
  cout << (num%4?"NO":"YES") << endl;

  return 0;
}