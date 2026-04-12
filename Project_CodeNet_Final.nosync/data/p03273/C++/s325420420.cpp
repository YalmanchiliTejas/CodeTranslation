#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int h,w;
	//int ans=0;
	cin >>h>>w;
	vector<string>s(h);
	vector<string>ans;
	bool none=true;
	rep(i,h){
		none=true;
		cin>>s[i];
		rep(j,w){
			none&=(s[i][j]=='.');
		}
		if(!none){
			ans.push_back(s[i]);
		}
	}
	/*
	clog<<endl;
	rep(i,ans.size()){
		clog<<ans[i]<<endl;
	}
	*/
	//clog<<ans.size()<<" "<<ans[1].size()<<endl;
	for(int j=0;j<ans[0].size();j++){
		none=true;
		for(int i=0;i<ans.size();i++){
			none&=(ans[i][j]=='.');
		}
		if(none==true){
			for (int i = 0; i < ans.size(); i++)
			{
				ans[i][j] = '0';
			}
		}
	}
	clog<<endl;
	rep(i,ans.size()){
		rep(j,ans[0].size()){
			if(ans[i][j]!='0'){
				cout<<ans[i][j];
			}
			if(j==ans[0].size()-1){
				cout<<endl;
			}
		}
	}
//	cout<<ans<<endl;
}