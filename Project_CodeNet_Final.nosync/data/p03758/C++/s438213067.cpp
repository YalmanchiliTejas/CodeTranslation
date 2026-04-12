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
const double EPS=1e-11;
const int MOD = 1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

vector<int> G[200];
int n;

bool ques(int a,int b){
	cout << "? ";
	for(int i = 0;i < n;i++){
		if(i == a || i == b) printf("1");
		else printf("0");
	}
	cout << endl;
	int d;
	cin >> d;
	return d;
}

signed main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			if(ques(i,j)) G[i].push_back(j);
		}
	}
	cout << "!";
	for(int i = 0;i < n;i++){
		for(int j = 0;j < G[i].size();j++){
			printf(" (%lld,%lld)",i,G[i][j]);
		}
	}
	return 0;
}