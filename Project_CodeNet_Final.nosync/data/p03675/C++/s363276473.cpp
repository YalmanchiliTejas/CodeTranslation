#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main(){
	ll n;
	cin >> n;
	vll A;
	ll i, j;
	for (i = 0; i < n; i++){
		ll a;
		cin >> a;
		A.push_back(a);
	}
	vll B(n, 0);
	if (n % 2 == 0){
		ll num = n - 1;
		for (i = 0; i < n / 2; i++){
			B[i] = A[num];
			num--;
			B[n - i - 1] = A[num];
			num--;
		}
	}
	else{
		ll num = n - 1;
		for (i = 0; i < (n - 1) / 2; i++){
			B[i] = A[num];
			num--;
			B[n - i - 1] = A[num];
			num--;
		}
		B[(n - 1) / 2] = A[num];
	}
	for (i = 0; i < n; i++){
		cout << B[i] << " ";
	}
	cout << endl;
}
