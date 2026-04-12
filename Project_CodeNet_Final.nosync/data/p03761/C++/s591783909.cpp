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
/*
vector<char>al(26);
al = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<char>AL(26);
AL = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
vector<char>NUM(10);
	NUM = { '0','1','2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' };
*/



int main() {
	vector<char>al(26);
	al = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	int N;
	cin >> N;
	vector<string>S(N);
	rep(i, N) {
		cin >> S[i];
	}
	vector<int>mal(26);
	int ch = 0;
	int CH = 100;
	rep(i, 26) {
		rep(j, N) {
			rep(k, S[j].size()) {
				if (S[j][k] == al[i]) {
					ch++;
				}
			}
			CH = min(CH, ch);
			ch = 0;
		}
		mal[i] = CH;
		CH = 100;
	}
	rep(i, 26) {
		rep(j, mal[i]) {
			cout << al[i];
		}
	}
	cout << endl;
}


