#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define ull unsigned long long
#define ll long long
template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}
template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.length();
	for(int i=0;i<n-1;++i) {
		if(s[i]=='A' && s[i+1]=='C') {cout << "Yes" << endl; return 0;}
	}
	cout << "No" << endl;
}