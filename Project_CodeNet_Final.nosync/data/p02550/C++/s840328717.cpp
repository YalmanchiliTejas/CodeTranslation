#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define nl '\n'
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x) cerr << #x << " = " << (x) << endl;

// template starts
typedef long long int ll;
#define int ll
// template ends here

void solve(){
	// code starts from here
	set<int> s;
	map<int,int> mp;
	vector<int> mod;
	int N,X, M;
	cin >> N >> X >> M;
	
	int start = 0;
	while(s.find(X) == s.end()){
		s.insert(X);
		
		mp[X] = mod.size();
	
		mod.pb(X);
		
		X = X*X;
		X %= M;
	}
	start = mp[X];
	
	int ans = 0;
	if(N <= (int)mod.size()){
		for(int i = 0; i < N; i++) ans += mod[i];
		cout << ans << endl;
		return;
	}
	
	N -= start;
	int len = (int)mod.size()-start;
	
	for(int i = 0; i < start; i++) ans += mod[i];
	
	int c1 = N/len, c2 = N%len;
	for(int i = start; i < (int)mod.size(); i++){
		ans += (c1*mod[i]);
	}
	for(int i = start; i < start+c2; i++) ans += mod[i];
	
	cout << ans << endl;
}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//startTime = clock();
	
	int T;
	//cin >> T;
	T = 1;
	while(T--){
		solve();
	}
	
	//cout << getCurrentTime() << endl;
	return 0;
}
