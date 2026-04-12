#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
using namespace std;
typedef  long long int lint;
typedef pair<int, int> P;
typedef pair<lint, lint> LLP;
typedef pair<char, char>CP;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)

const lint MOD = pow(10, 9) + 7;

lint gcd(lint a, lint b) {
	//aとbの最大公約数を返す
	if (a < b)swap(a, b);
	if (a % b == 0)return b;
	return gcd(a % b, b);
}

lint lcm(lint a, lint b) {
	//aとbの最小公倍数を返す
	return a / gcd(a, b) * b;
}

/*
vector<char>al(26);
al = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<char>AL(26);
AL = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
vector<char>NUM(10);
	NUM = { '0','1','2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' };
*/


int main() {
	int N;
	string S;
	int K;
	cin >> N >> S >> K;
	rep(i, N) {
		if (S[i] == S[K - 1]) {
			cout << S[i];
		}
		else {
			cout << '*';
		}
	}
	cout << endl;
}
