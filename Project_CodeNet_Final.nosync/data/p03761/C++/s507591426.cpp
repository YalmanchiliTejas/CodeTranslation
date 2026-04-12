#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1e9+10)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))



int main(void){
	int n;
	cin>>n;
	string s;
	vector<string> S;
	rep(i,n){
		cin>>s;
		S.push_back(s);
	}

	vector<int> alphabet;
	rep(i,26){
		alphabet.push_back(INF);
	}

	rep(i,S.size()){
		vector<int> count_alphabet;
		rep(j,26){
			count_alphabet.push_back(0);
		}

		rep(j,S[i].size()){
			count_alphabet[S[i][j] - 'a']++;
		}

		rep(j,26){
			alphabet[j] = min(alphabet[j], count_alphabet[j]);
		}
	}

	string ans = "";
	rep(i,26){
		while(alphabet[i] > 0){
			ans.push_back(i+'a');
			alphabet[i]--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
