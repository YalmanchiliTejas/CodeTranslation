#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <map>
#include <string>
#include <utility>

#define repd(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;

using namespace std;

int inputValue(){
	int a;
	cin >> a;
	return a;
}

void inputArray(int *p,int a){
	rep(i,a){
		cin >> p[i];
	}
}

void inputVector(vector<int> *p,int a){
	rep(i,a){
		int input;
		cin >> input;
		p -> push_back(input);
	}
}

template <typename T>
void output(T a,int precision){
	if(precision > 0){
		cout << setprecision(precision) << a << "\n";
	}else{
		cout << a << "\n";
	}
}

vector<ll> a,p;
ll f(ll n,ll x){
	if(n==0){
		if(x<=0){
			return 0;
		}else{
			return 1;
		}
	}else if(x<=1+a[n-1]){
		return f(n-1,x-1);
	}else{
		return p[n-1]+1+f(n-1,x-2-a[n-1]);
	}
}

int main(){
	//source
	ll n,x;
	cin >> n >> x;
	a.push_back(1);
	p.push_back(1);
	rep(i,n){
		a.push_back(a[i]*2+3);
		p.push_back(p[i]*2+1);
	}

	cout << f(n,x) << endl;
	return 0;
}
