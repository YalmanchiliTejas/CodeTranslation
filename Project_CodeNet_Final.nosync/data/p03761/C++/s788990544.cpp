#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()

#define endl "\n"
#define pb push_back
#define elif else if
#define cout_db cout << fixed

#define MOD 1000000007LL
#define PI 3.1415926

typedef long long ll;

template <typename T>
inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <typename T>
inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template <typename T>
inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template <typename T>
inline T nHr(T a,T b){return nCr(a+b-1,b);}
template <typename T>
inline T POW(T a,T b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	string s[50];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int letters[26];
	for (int i = 0; i < 26; i++) {
		letters[i] = 1145141919;
	}
	for (int i = 0; i < n; i++) {
		int cnt[26] = {0};
		for (int j = 0; j < s[i].size(); j++) {
			cnt[s[i][j] - 'a']++;
		}
		for (int j = 0; j < 26; j++) {
			if(cnt[j] < letters[j]) letters[j] = cnt[j];
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < letters[i]; j++) {
			cout << (char)('a'+i);
		}
	}
	cout << endl;

	return 0;
}