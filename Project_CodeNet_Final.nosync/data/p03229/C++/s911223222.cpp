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
clock_t startTime;
long double getTime(){
	return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
}

int main(){
	startTime=clock();        // 1 1 3 4 5 9
	int n;					//	4 9 1  5 1 3 // 3 9 1 5 1 4
 	cin >> n;
	ll a[n];
	FOR(i,n){
		cin >> a[i];
	}
	sort(a,a+n);
	ll sum=0,sum1=0,i=0,j=n-1;
	int b[n],k=0;
	if(n%2){
		std::vector<ll> v;
		std::vector<ll> v1;
		k=n/2;
		v.eb(a[k]);
		v1.eb(a[k]);
		while(i < k){
		v.PB(a[i]);
		v.PB(a[j]);
		v1.PB(a[j]);
		v1.PB(a[i]);
		i++;j--;
		}
		for(int l=0;l<n-1;l++) sum+=abs(v[l]-v[l+1]);
		for(int l=0;l<n-1;l++) sum1+=abs(v1[l]-v1[l+1]);
			
	}
	else{
		std::vector<ll> v,v1;
		k=n/2;
		int t=k-1;
		v.eb(a[k]);
		v1.eb(a[t]);
		while(i < k){
			v.eb(a[i]);
			v.eb(a[j]);
			i++;j--;

		}
		j=n-1;i=0;
		while(j>t){
			v1.eb(a[j]);
			v1.eb(a[i]);
			i++;j--;
		}
		for(int l=0;l<n-1;l++) sum+=abs(v[l]-v[l+1]);
		for(int l=0;l<n-1;l++) sum1+=abs(v1[l]-v1[l+1]);


	
	}

	cout << max(sum,sum1);
	
	return 0;
}