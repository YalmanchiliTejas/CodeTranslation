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
pair<ll,ll> func(ll last,ll eaten,int level,V&pathi,V&legth){
	P data=mp(last,eaten);//last,eaten
	clog << level << " : " <<endl;
	if (level == 0)
	{
		data=mp(max(0LL,data.F-1LL),eaten+min(1LL,max(last,0LL)));
	}
	else if (legth[level] <= last)
	{
		data=mp(data.F-legth[level],data.S+pathi[level]);
	}
	else
	{
		if (data.F >=1)
		{
			data.F --;
		}
		if(data.F>0){
		data=func(data.F,data.S,level-1,pathi,legth);
		}
		if(data.F>=1){
			data=mp(data.F-1,data.S+1);
		}
		if (data.F > 0)
		{
			data = func(data.F, data.S, level - 1, pathi, legth);
		}
		if (data.F > 0)
		{
			data.F --; 
		}
	}
//	clog<<level<<" : "<<data.F<<" , "<<data.S<<endl;
	return data;
}
int main(){
	int n;
	ll x;
//	ll ans=0LL;
	cin >>n>>x;
	V pathi(51,1LL), legth(51,1LL);
	rep(i,51){
		if(i!=0){
			pathi[i]=pathi[i-1]*2+1LL;
			legth[i]=legth[i-1]*2+3LL;
			//clog<<pathi[i]<<" "<<legth[i]<<endl;
		}
	}
	P ans=func(x,0,n,pathi,legth);
	cout<<ans.S<<endl;
}
/*
v p l
0 1 1
1 3(2*2 +1) 5(1*2+3)
2 7(3*2 +1)  13(5*2+3)
3 15(7*2 +1) 29(13*2+3)
Vn ((V(n-1)*2 +1)  (2*(V(n-1))+3)

*/