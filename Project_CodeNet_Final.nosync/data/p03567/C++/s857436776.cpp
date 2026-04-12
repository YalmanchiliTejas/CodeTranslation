#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define pq priority_queue
#define rep(i,n) for (int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define INF 2000000009
string s; 
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	for (int i=1;i<s.size();++i){
		if (s[i-1]=='A'&&s[i]=='C'){
			cout<<"Yes";return 0;
		}
	}
	cout<<"No";
}