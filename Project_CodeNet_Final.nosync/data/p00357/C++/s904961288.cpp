#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9 + 7;
int main(){
	int N;
	std::cin >> N;
	vector<int> vec;
	for(int a = 0;a < N;a++){
		int b;cin >> b;
		vec.push_back(b);
	}
	int ins  = 0;
	bool flag1 = true;
	bool flag2 = true;
	for(int a = 0;a < N-1;a++){
		ins-=10;
		ins = max(ins,vec.at(a));
		if(ins < 10)flag1 = false;
	}
	ins = 0;
	for(int a = N-1;a >= 1;a--){
		ins -=10;
		ins = max(ins,vec.at(a));
		if(ins < 10)flag2 = false;
	}
	cout<<(flag1&&flag2?"yes":"no")<<endl;
}

