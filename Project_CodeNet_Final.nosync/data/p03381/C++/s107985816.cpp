#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i,n){
		cin >> a.at(i);
		b.at(i)=a.at(i);
	}
	sort(b.begin(),b.end());
	rep(i,n){
		if(a.at(i)>=b.at(n/2)) cout << b.at(n/2-1) << endl;
		else cout << b.at(n/2) << endl;
	}
}