#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
 
using namespace std;
 
#define int long long
//typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,a[200000],b[200000];
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n;i++){
		if(i % 2 == 0) b[i / 2] = a[n - i - 1];
		else b[n - i / 2 - 1] = a[n - i - 1];
	}
	for(int i = 0;i < n;i++) cout << (i ? " " : "") << b[i];
	cout << endl;
	return 0;
}