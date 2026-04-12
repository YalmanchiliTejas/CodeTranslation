#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
int N;
int p[200];

vector<int> ans;
void proceed(int k){
	ans.pb(k);
	for(int i=k;i<N;i++) swap(p[i],p[i-k]);
}

void Swap(int i,int j){
	rep(k,i+1) proceed(1);
	proceed(N-1);
	rep(k,N-(i+1)) proceed(1);
}
int main(){
	cin>>N;
	rep(i,N) cin>>p[i];
	rep(t,20){
		int k = rand()%(N-1)+1;
		proceed(k);
	}
	rep(i,N-1) rep(j,N-1) if(p[j+1]<p[j]){
		Swap(j,j+1);
	}
	vector<int> nans;
	int cnt1 = 0;
	for(int v:ans){
		if(v==1){
			cnt1++;
			if(cnt1==N) cnt1 = 0;
		}else{
			rep(t,cnt1) nans.pb(1);
			nans.pb(v);
			cnt1 = 0;
		}
	}
	rep(t,cnt1) nans.pb(1);
	ans = nans;
	cout<<ans.size()<<endl;
	for(int v:ans) cout<<v<<endl;

//	rep(i,N) show(p[i]);
}
