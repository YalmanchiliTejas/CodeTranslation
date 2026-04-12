#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false); //cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

using namespace std;
typedef long long ll;
typedef long double ld;

int n, k;
	
void solve(){
	cin >> n;
	k = n==3 || n==5 || n==7;
	cout << (k?"YES":"NO");
}	

int main(){ FIO;
	solve();
return 0;}