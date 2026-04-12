#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e9 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio	
	int h,w;
	cin >> h >> w;
	std::vector<string> a(h);
	for(int i=0; i<h; i++)cin >> a[i];
	std::vector<bool> row(h,false);
	std::vector<bool> col(w,false);
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(a[i][j] == '#'){
				row[i]=true;
				col[j]=true;
			}
		}
	}
	for(int i=0; i<h; i++){
		if(row[i]){
			for(int j=0; j<w; j++){
				if(col[j]){
					cout << a[i][j];
				}
			}
			cout << "\n";			
		}
	}
	return 0;
}

