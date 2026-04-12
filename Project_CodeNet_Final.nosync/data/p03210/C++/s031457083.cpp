#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>     
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
#define INF 2000000
#define MOD 1000000007
#define sym cout<<"---------"<<endl;
#define ll long long
#define mk make_pair
#define en endl
#define RE return 0
#define int ll
#define P pair<int,int>
using namespace std;
int dx[5]={1,0,-1,0,0},dy[5]={0,1,0,-1,0};
int gcd(int a,int b){if(a%b==0){return b;}else return gcd(b,a%b);}
int lcm(int a,int b){if(a==0){return b;} return a/gcd(a,b)*b;}

signed main(){
	int n; cin>>n;
	if((n==5 || n==7) || n==3) cout<<"YES"<<en;
	else cout<<"NO"<<en;
}
