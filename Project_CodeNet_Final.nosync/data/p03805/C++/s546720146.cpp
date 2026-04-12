#include "bits/stdc++.h"
#define rep(i,a,n) for(int i = (a);i < (n);i++)
	
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int ans = 0,cnt = 0,visiting = 1,a[1000],b[1000],n,m;
bool is_visited[8] = {false};

void dfs(){
	cnt++;
	if(cnt == n){
		ans++;
		return ;
	}
	
	rep(i,0,m){
		if(a[i] == visiting && !is_visited[b[i]-1]){
			visiting = b[i];
			is_visited[a[i]-1] = true;
			
			dfs();
			cnt--;
			visiting = a[i];
			is_visited[a[i]-1] = false;
			
		}
		else if(b[i] == visiting && !is_visited[a[i]-1]){
			visiting = a[i];
			is_visited[b[i]-1] = true;
			
			dfs();
			cnt--;
			visiting = b[i];
			is_visited[b[i]-1] = false;
			
		}
	}
	return;
}

int main(){
	cin >> n >> m;
	
	rep(i,0,m){
		cin >> a[i] >> b[i];
	}
	
	dfs();
	
	cout << ans << endl;
	
	
  	return 0;
}



