#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1) * a % MOD;
	}
}

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}else{
		return gcd(b, a%b);
	}
}

int main(void){
	/*priority_queue<int,vector<int>,greater<int>> sho, sho_del;
	priority_queue<int> ko;
	int n;
	cin>>n;
	int a;
	vector<int> A;
	rep(i,n){
		cin>>a;
		A.push_back(a);
	}

	rep(i,n){
		if(i == 0){
			sho.push(A[i]);
			ko.push(A[i]);
			continue;
		}
		if(ko.top() < A[i]){
			int max = ko.top();
			ko.pop();
			ko.push(A[i]);
			sho_del.push(max);
		}else if(ko.top() == A[i]){

		}
	}*/

	int n;
	cin>>n;
	int a;
	vector<int> A;
	rep(i,n){
		cin>>a;
		A.push_back(a);
	}

	vector<int> ko;
	rep(i,n){
		if(i == 0){
			ko.push_back(A[i]);
			continue;
		}
		if(ko[ko.size()-1] >= A[i]){
			ko.push_back(A[i]);
			continue;
		}
		int l = -1;
		int r = ko.size() - 1;
		while(r-l > 1){
			int chu = (l+r)/2;
			if(ko[chu] < A[i]){
				r = chu;
			}else{
				l = chu;
			}
		}
		ko[r] = A[i];
	}
	//cout<<ko[0]<<" "<<ko[1]<<endl;
	cout<<ko.size()<<endl;
	return 0;
}
