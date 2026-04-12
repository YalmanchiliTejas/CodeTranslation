#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <random>
#include <vector>
//#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
 
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define all(a) (a).begin(), (a).end()
#define cae cout<<ans<<endl
 
int main()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	
	c*=2;
	int ans=INT_MAX;
	int tmp;
	rep(i,max(x,y)+1){
		tmp=c*i+a*max(0,x-i)+b*max(0,y-i);
		ans=min(ans,tmp);
	}
	cae;
	
	return 0;
}