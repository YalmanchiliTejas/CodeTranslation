#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)
bool cmp(string &a,string &b) {
	return a+b<b+a;
}
void solve(int test_case) {
	int n;
	cin>>n;
	int arr[26];
	fill(arr,arr+26,-1);
	while(n--){
		string s;
		cin>>s;
		unordered_map<char,int> m;
		for(char c:s)m[c]++;
		for(char c='a';c<='z';c++) {
			if(arr[(int)(c-'a')]==-1)arr[(int)(c-'a')]=m[c];
			arr[(int)(c-'a')]=min(arr[(int)(c-'a')],m[c]);
		}
	}
	vector<string> v;
	for(int i=0;i<26;i++) {
		if(arr[i]<=0)continue;
		while(arr[i]--)v.PUB(string(1,(char)(i+'a')));
	}
	sort(v.begin(),v.end(),cmp);
	string sol="";
	for(string s:v)sol+=s;
	cout<<sol;
}

int main() {
	
	////// FILE BASED IO////
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
}	
