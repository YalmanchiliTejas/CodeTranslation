#include <bits/stdc++.h>
using namespace std;

unsigned long long int ret;
bool check = false;

void solve(vector<unsigned long long int> T, int ize, unsigned long long int find, unsigned long long int how){
	unsigned long long int miru = find * how;
	if(check == true) return;
	for(int i = ize; i >= 0; i --){
		if(miru % T[i] == 0){
			if(i == 0){
				ret = miru;
				check = true;
				return ;
			}
		}else {
			if(check == true)return ;
			else solve(T, ize, find, how + 1);
			return ;
		}
	}
}

int main(){
	// int N;
	// vector<unsigned long long int> T;
	// cin >> N;
	// unsigned long long int in;
	// for(int i = 0; i < N; i++){
	// 	cin >> in;
	// 	T.push_back(in);
	// }
	// sort(T.begin(), T.end());
	// if(T.size() == 1)cout << T[0] << endl;
	// else{solve(T, T.size() - 1, T[T.size() - 1], 1);
	// 	cout << ret << endl;
	// }
	int red, green, blue;
	cin >> red >> green >> blue;
	int sum = red * 100 + green * 10 + blue;
	if(sum % 4 == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}