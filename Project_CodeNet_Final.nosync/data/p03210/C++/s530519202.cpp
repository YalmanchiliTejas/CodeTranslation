//inlclude before define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
#include<assert.h>
//#include<deque>
#include<iomanip>
#include<set>
#include<tuple>
#include<map>
using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef pair<int, int> P1;
typedef long long int ll;

//define
#define INF 1e9
#define NUM 1000000007
#define all(x) begin(x), end(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))


int main(void) {
	int n;
	cin>>n;

	if(n==7 || n==5||n==3){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}



