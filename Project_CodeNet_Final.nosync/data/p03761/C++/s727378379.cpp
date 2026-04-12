#include<bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vi  = vector<int>;
#define _GLIBCXX_DEBUG
#define IO_STREAM cin.tie(0);ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define rep(i,sta,end) for(ll i=sta;i<end;++i)
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define INF 1000000000000000LL
const ll MOD = 1000000007;
const double PI = acos(-1);
//||
#define DBG(a,b,c,d) //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl

signed main(){
	IO_STREAM;
	int n;
	cin>>n;
	string S;
	int cnt[26]={0};
	rep(i,0,n){
		cin>>S;
		int tmp_cnt[26]={0};
		rep(j,0,S.size()){
			if(i==0){
				cnt[S[j]-'a']++;
			}
			else{
				if(cnt[S[j]-'a']>0){
					tmp_cnt[S[j]-'a']++;
				}
			}
		}
		if(i==0) continue;
		rep(k,0,26){
			if(cnt[k]>0){
				cnt[k]=min(cnt[k],tmp_cnt[k]);
			}
		}
	}
	string ans;
	rep(i,0,26){
		rep(j,0,cnt[i]){
			ans+=i+'a';
		}
	}
	DBG("","","","");
	cout<<ans<<endl;
	return 0;
}
