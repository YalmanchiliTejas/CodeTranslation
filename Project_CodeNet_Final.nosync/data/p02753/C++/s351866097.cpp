#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF  = 0x3f3f3f3f;
const ll  mod  = 1e9 + 7;
const ll  maxn = 1e6 + 5;

string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	if(s=="AAA" || s=="BBB"){
		cout<<"No";
	}else
	    cout<<"Yes";
	return 0;
}