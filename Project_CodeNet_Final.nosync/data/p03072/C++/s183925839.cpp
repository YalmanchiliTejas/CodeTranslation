#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back 

int main(){

	int n;
	int cont = 0;

	cin >> n;

	int mx, aux;
	vector<int> v, m;	
	for(int i = 0; i < n; i++){
		cin >> aux;
		v.pb(aux);
	}

	mx = v[0];
	for(int i = 0; i < n; i++){
		if(v[i] > mx){
			m.pb(v[i]);
			mx = v[i];
		}else{
			m.pb(mx);
		}
	}

	for(int i = 0; i < n; i++){
		if(v[i] >= m[i])
			cont++;
	}

	cout << cont << endl;

return 0;
}

