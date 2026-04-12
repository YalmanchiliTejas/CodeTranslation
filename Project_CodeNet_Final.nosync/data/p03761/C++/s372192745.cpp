#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
typedef long long ll;
const int INF = 1000000000;
const long INF64 = 1000000000000000ll;
const ll MOD = 1000000007ll;


int main(){
	std::vector<int> miin(26,0);
	int n;
	std::cin >> n;
	string ss;
	std::cin >> ss;
	rep(j,ss.size()){
		miin[ss[j]-97]++;
	}
	rep(i,n-1){
		string s;
		std::cin >> s;
		std::vector<int> dum(26,0);
		rep(j,s.size()){
			dum[s[j]-97]++;
		}
		rep(j,26){
			miin[j]=min(miin[j],dum[j]);
		}
	}
	string ans;
	rep(i,26){
		rep(j,miin[i])std::cout << (char)(i+97);
	}
	std::cout  << std::endl;
	
}
