#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << "   ";
		}
		cout << endl;
	}
}


int main(){// 全探索：全列挙 4　パ研杯2019 C - カラオケ　これが解ければ全探索に慣れたと思って良いです。
	ll A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	
	//ll ans = 100100100100100;
	//1. 全部ABピザ
	ll money1 = 2 * max(X, Y) * C;

	//2.　X，Y少ない方のピザの分を全部ABピザ
	ll money2 = 0;
	if(X > Y){
		money2 += Y * 2 * C;
		money2 += (X-Y) * A;
	}
	else{
		money2 += X * 2 * C;
		money2 += (Y-X) *B;
	}

	//3 ABピザを買わない
	ll money3 = A * X + B * Y;

	cout << min( min(money1, money2), money3) << endl;
}