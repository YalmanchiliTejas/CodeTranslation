#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <regex>
#include <time.h>
#include <complex>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
#define pb push_back
#define mp make_pair
#define sc second
#define fr first
#define stpr setprecision
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define rep(i,n) for(ll i=0;i<(n);++i)
#define Rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rRep(i,a,b) for(int i=a;i>=b;i--)
#define crep(i) for(char i='a';i<='z';++i)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define ALL(x) (x).begin(),(x).end()
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define endl '\n'
typedef long long ll;

int main(){

	//int N, M, *A, *B, i, j, *W, *flag, sum=0, start, end, length, tmp;
	int H, W, A, B, C, **ans, flag=0, i, j, ans_0=0, ans_W=0;
	char S[3], T[10], U[10];


	scanf("%s", S);


	if (S[0] == S[1] && S[1] == S[2]){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}


	/*
	ans = (int **)malloc(sizeof(int *)* H);


	for (i = 0; i<H; i++) {
		ans[i] = (int *)malloc(sizeof(int)* W);
	}

	for (i = 0; i < H; i++){
		for (j = 0; j < W; j++){
			ans[i][j] = 0;
		}
	}
	*/

	return 0;

}
    
