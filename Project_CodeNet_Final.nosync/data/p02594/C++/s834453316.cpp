#define _USE_MATH_DEFINES
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <tuple>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<vector<int>> VVI;
typedef vector<vector<long long>> VVLL;
typedef vector<vector<bool>> VVB;
typedef vector<vector<double>> VVD;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(a) (a).begin(),(a).end()

const int MOD = 1000000007;

template<class T>bool chmax(T &a, const T &b){
	if(a<b){
		a=b;
		return true;
	}
	return false;
}

template<class T>bool chmin(T &a, const T &b){
	if(a>b){
		a=b;
		return true;
	}
	return false;
}

void debug(VI &arr){
	int n=arr.size();
	rep(i,n){
		cout<<arr.at(i)<<endl;
	}
}

void debug(VVI &board){
	int h = board.size();
	int w = board.at(0).size();
	rep(i,h){
		rep(j,w){
			cout << board.at(i).at(j) << " ";
		}
		cout<<endl;
	}
}

void debug(VVLL &board){
	int h = board.size();
	int w = board.at(0).size();
	rep(i,h){
		rep(j,w){
			cout<<board.at(i).at(j)<<" ";
		}
		cout<<endl;
	}
}

void debug(VS &board){
	int h = board.size();
	rep(i,h){
		cout<<board.at(i)<<endl;
	}
	return;
}

LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}

LL lcm(LL a,LL b){
	return a*b/gcd(a,b);
}

int main(){
	//cout<<fixed;
	//cout<<setprecision(9)<<...
	int x;
	cin>>x;
	if(x>=30)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
