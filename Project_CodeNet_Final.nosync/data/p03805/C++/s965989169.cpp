#include<iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define what_is(x) cerr << #x << " is " << x << endl;
#define MT make_tuple
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FOR(i,n) for (int i=0;i < n ; i++)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int dfs(int x,std::vector<int> v[],bool visited[], int n ){
	//visited[x]=true;
	bool s=true;
	int sum=0;
	FOR(i,n) if(visited[i]!=true) s=false;
	if(s) return 1;
	
	FOR(i,v[x].size()){
		if(!visited[v[x][i]]) {
			visited[v[x][i]]=true;
			sum+=dfs(v[x][i],v,visited,n); 
			visited[v[x][i]]=false;
		}
	}
	return sum;
}


int main(){
	int n,m,a,b;
	cin >> n >>m;
	vector<int> v[n];
	FOR(i,m){
		cin >> a >> b;
		v[a-1].PB(b-1);
		v[b-1].PB(a-1);
	}
	bool visited[n];
	FOR(i,n)visited[i]=0;
	visited[0]=true;
	cout << dfs(0,v,visited,n);

	return 0;
}