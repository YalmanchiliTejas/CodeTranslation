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
	
	ll ans = 100100100100100;
	int larger_num = max(X, Y);
	for(int i=0;i<=larger_num * 2; i++){
		//if( (X - i/2) < 0 || (Y - i/2) < 0) continue;
		ll money = i * C;//ABピザをi枚買う
		if( (X - i/2) > 0) money += ( X - i/2 ) * A;
		if( (Y - i/2) > 0) money += ( Y - i/2 ) * B;
		ans = min(ans, money);
		//if(money == 100000000)cout << " A: " << (X-i/2) << " B: " << (Y-i/2) << " C: " << i << endl;
	}
	cout << ans << endl;
	
	//以下のやり方だと，AもBも必要最小限の枚数になるが，値段が最小とは限らない
	// ll min_num = min(X, Y);//AとBをそれぞれmin_num枚買うか,Cを2*min_num枚買うか 
	// ll money = min( (A + B)*min_num, 2*C*min_num);
	// ll left_num = max(X, Y) - min_num;
	// if(X > Y) money += A * left_num;
	// else money += B * left_num;
	// cout << money << endl;

}