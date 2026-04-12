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
#include <unordered_map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=150;
//ここまでテンプレ
int main(){
	int H,W;
	cin>>H>>W;
	string S[SIZE];
	for(int i=0;i<H;i++)
		cin>>S[i];
	int tate[SIZE]={},yoko[SIZE]={};
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			if(S[i][j]=='#')
				tate[i]++;
	for(int j=0;j<W;j++)
		for(int i=0;i<H;i++)
			if(S[i][j]=='#')
				yoko[j]++;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++)
			if(tate[i] && yoko[j])
				cout<<S[i][j];
		if(tate[i])
			cout<<endl;
	}
	return 0;
}