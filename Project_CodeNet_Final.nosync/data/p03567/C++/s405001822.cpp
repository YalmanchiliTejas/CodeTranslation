#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
#define MOD 1000000007

using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int iy[]={0, 0, 1, -1};
int ix[]={1, -1, 0, 0};

int n, m;
string s;

int main(){
	cin >> s;
	for(int i=0;i<s.size();i++){
			if(s[i]=='A'&&s[i+1]=='C'){
				cout << "Yes" << endl;
				return 0;
			}
	}
	cout << "No" << endl;
	return 0;
}