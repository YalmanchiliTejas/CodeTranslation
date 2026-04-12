#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 1000000007
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
	ll n;cin>>n;
	string s;cin>>s;
	vector<ll> ans(n),ins(n);

	ll dx[4]={1,1,-1,-1};
	ll dy[4]={1,-1,1,-1};//最初の二匹がどちらの動物か

	bool can=false;
	rep(i,4){
		ans[0]=dx[i];
		ans[1]=dy[i];

		for(ll j=1;j<n-1;j++){
			if(s[j]=='o' && ans[j]==1 || s[j]=='x' && ans[j]==-1){//羊がoといっている または　オオカミがxといっている　なら
				ans[j+1]=1*ans[j-1];//jに隣り合うのは同じ動物
			}else if(s[j]=='o' && ans[j]==-1 || s[j]=='x' && ans[j]==1){//オオカミがoといっている または　羊がxといっている　なら
				ans[j+1]=-1*ans[j-1];//jに隣り合うのは違う動物
			}
		}

		if(((s[0]=='o' && (ans[0]==1 && ans[1]==ans[n-1] || ans[0]==-1 && ans[1]!=ans[n-1]))//s[0]がoのとき
		||  (s[0]=='x' && (ans[0]==1 && ans[1]!=ans[n-1] || ans[0]==-1 && ans[1]==ans[n-1])))//s[0]が×のとき
		&& ((s[n-1]=='o' && (ans[n-1]==1 && ans[0]==ans[n-2] || ans[n-1]==-1 && ans[0]!=ans[n-2]))//s[n-1]がoのとき
		||  (s[n-1]=='x' && (ans[n-1]==1 && ans[0]!=ans[n-2] || ans[n-1]==-1 && ans[0]==ans[n-2])))//s[n-1]がxのとき
		){//0番とn-1番の証言が一致するか
			can=true;
			break;
		}
	}

	if(can){
		rep(i,n){
			if(ans[i]==1){
				cout<<'S';
			}else{
				cout<<'W';
			}
		}
		cout<<endl;
	}else{
		cout<<-1<<endl;
	}

	return 0;
}