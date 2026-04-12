#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n); i >= 0; i--)
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define REVSORT(c) SORT(c);REVERSE(c)
#define ALL(x) (x).begin(),(x).end()
const long long MOD = 1000000007;
typedef long long ll;

int string_count(string S, char a){
	int cnt = 0;
	for(int i = 0; i < S.length(); i++){
		if(S.at(i) == a)cnt++;
	}
	return cnt;
}

int main(){
	int N;
	cin >> N;
	vector<string> S(N);
	rep(i, N)cin >> S[i];
	
	vector<int> C(26, 100);
	
	for(int i = 0; i < N; i++){
		char Alp = 'a';
		for(int j = 0; j < 26; j++){
			int cnt = string_count(S[i], Alp);
			C[j] = min(C[j], cnt);
			Alp++;
		}
	}
	
	char A = 'a';
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < C[i]; j++){
			cout << A;
		}
		A++;
	}
	cout << endl;
}