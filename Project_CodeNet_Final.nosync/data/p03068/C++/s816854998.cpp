#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,k;cin >> n;
	string s;cin >> s;
	cin >> k;
	k--;
	rep(i,n) if(s.at(i)!=s.at(k)) s.at(i)='*';
	cout << s << endl;
}