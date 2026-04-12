#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n;cin>>n;
	string s;cin>>s;
	
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			vector<int> a(n,0);
			a[0] = i;
			a[1] = j;
			for(int k = 1; k < n - 1; k++) {
				if(a[k] == 0){//sheep
					if (s[k] == 'o'){
						a[k + 1] = a[k - 1];
					}
					else{
						a[k + 1] = !a[k - 1];
					}
				}
				else{
					if (s[k] == 'o'){
						a[k + 1] = !a[k - 1];
					}
					else{
						a[k + 1] = a[k - 1];
					}
				}
			}
			bool flag = true;
			if (a[n - 1] == 0){
				if (s[n - 1] == 'o'){
					if(a[n - 2] != a[0]){
						flag = false;
					}
				}
				else{
					if(a[n - 2] == a[0]){
						flag = false;
					}
				}
			}
			else {
				if (s[n - 1] == 'o'){
					if(a[n - 2] == a[0]){
						flag = false;
					}
				}
				else{
					if(a[n - 2] != a[0]){
						flag = false;
					}
				}
			}

			if (a[0] == 0){
				if (s[0] == 'o'){
					if(a[n - 1] != a[1]){
						flag = false;
					}
				}
				else{
					if(a[n - 1] == a[1]){
						flag = false;
					}
				}
			}
			else {
				if (s[0] == 'o'){
					if(a[n - 1] == a[1]){
						flag = false;
					}
				}
				else{
					if(a[n - 1] != a[1]){
						flag = false;
					}
				}
			}
			if (flag){
				for(int l = 0; l < a.size(); l++) {
					if(a[l] == 0){
						cout << 'S';
					}
					else{
						cout << 'W';
					}
				}
				cout << endl;	
				return 0;
			}
		}	
	}
	cout << -1 << endl;
	return 0;
}