#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
ll max(ll a, ll b){ 
	if(a >= b) return a;
	else if(a < b) return b;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	ll n;
	cin >> n;
	string s;
	vector<int> cnt(26, 0);
	rep(i, n){
		cin >> s;
		rep(j, 26){
			int temp_cnt = 0;
			rep(k, s.size()){
				if(s[k] == 'a' + j)temp_cnt += 1;
			}
			if(i != 0)cnt[j] = min(cnt[j], temp_cnt);
			else if(i == 0)cnt[j] = temp_cnt;
		}
	}
	rep(i,26){
		rep(j, cnt[i]){
			cout << char('a'+ i);
		}
	}
	cout << endl;
	
}