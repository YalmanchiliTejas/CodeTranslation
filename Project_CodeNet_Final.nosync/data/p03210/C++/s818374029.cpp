#include<stdio.h>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>     
#include <numeric>
#include <utility>
#include <queue>
#include <set>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>
#include <limits>
#include <vector>
using namespace std;
#define ll long long
#define ld long double
#define rep(a,t) for(int a=0;a<t;++a) 
#define forever while(true)
#define Sort(a) sort(a.begin(),a.end())
#define Reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define print_double(val,a) cout << fixed << setprecision(a) << val << endl;
ll mod = 1e9 + 7;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin>>n;
  if(n==3||n==5||n==7){cout<<"YES"<<endl;}
  else{cout<<"NO"<<endl;}
	return 0;
}
