#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(vec) vec.begin(),vec.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define SZ(x) (int)x.size()

typedef  vector<string> vs;
typedef  vector<int> vi;


int main(){
	
	int n,m; 
	
	string s; 
	
	cin >> n >> m; 
	
	vs v;
	
	int ans[n+1][m+1];
	
	f(i,0,n){
		f(j,0,m){
			ans[i][j] = 0;
		}
	}
	
	
	f(i,0,n){
		cin >> s;
		
		v.pb(s);
	}
	
	bool ok;
	
	f(i,0,n){
		ok = true;
		f(j,0,m){
			if(v[i][j]=='#'){
				ok = false;
				break;
			}
		}
		
		if(ok){
			f(j,0,m){
				ans[i][j] = 1;
			}
		}
	}
	
	f(j,0,m){
		ok = true;
		f(i,0,n){
			if(v[i][j]=='#'){
				ok = false; 
				break;
			}
		}

		if(ok){
			f(i,0,n){
				ans[i][j] = 1;
			}
		}
	}
	
	f(i,0,n){
		ok = true;
		f(j,0,m){
			if(!ans[i][j]){
				cout <<v[i][j];
				ok = false;
			}
		}
		
		if(!ok)cout << endl;
	}
	
	return 0;
	
	
}

