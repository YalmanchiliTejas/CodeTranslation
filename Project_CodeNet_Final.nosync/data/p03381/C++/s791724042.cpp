#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
using namespace std;
//#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=100050;
//ここまでテンプレ
int main(){
	int N;
	cin>>N;
	vint A,B;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		A.pb(a);
		B.pb(a);
	}
	sort(B.begin(),B.end());
	//cout<<B[N/2-1]<<endl;
	for(int i=0;i<N;i++){
		if(A[i]<=B[N/2-1])
			cout<<B[N/2]<<endl;
		else
			cout<<B[N/2-1]<<endl;
	}
	return 0;
}