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
#define Yes() printf("Yes\n")
#define No() printf("No\n")
 
using namespace std;
 
#define int long long
//typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,a[50],sum = 0,ans = 0;
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	while(1){
		int ma = -INF,mai;
		for(int i = 0;i < n;i++){
			if(ma < a[i]){
				mai = i;
				ma = a[i];
			}
		}
		if(ma < n) break;
		int cnt = a[mai] / n;
		ans += cnt;
		for(int i = 0;i < n;i++){
			if(mai == i) a[i] %= n;
			else a[i] += cnt;
		}
	}
	cout << ans << endl;
	return 0;
}