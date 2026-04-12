#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
#define MOD 1000000007

using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int iy[]={0, 0, 1, -1};
int ix[]={1, -1, 0, 0};

long long int n, k;
long long int ans;
int main(){
	cin >> n >> k;
	if(k==0){
		ans = n*n;
	}else{
		for(long long int i = k+1;i <=n;i++){
			ans += (n+1) / i * (i-k);
			if((n+1+i)%i!=0){
				if((n+1+i)%i - k>0) ans+=(n+1+i)%i - k;
			}
		}
	}
	cout << ans << endl;
	return 0;
}