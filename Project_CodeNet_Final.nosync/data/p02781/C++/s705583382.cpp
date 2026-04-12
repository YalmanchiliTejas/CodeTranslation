#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int siz=2e5+1;
const long inf=1e9;
long calc(int x, int k){
    if(k == 0) return 1;
	else if(k == 1) return 9 * x;
	else if(k == 2) return 81 * x * (x-1) / 2;
    else if(k == 3) return 729 * x * (x-1) * (x-2) / 6;
    else return 0;
}
int main(){
	string s; int K; cin>>s>>K;
	int n = s.size(); int k = K;
	int ans = 0;
	rep(i,0,n){
		if(s[i] == '0') continue;
		ans += calc(n - 1 - i, k) + (s[i] - '0' - 1) * calc(n - 1 - i, k - 1);
		k--;
	}cout<<ans + (k == 0)<<endl;
}