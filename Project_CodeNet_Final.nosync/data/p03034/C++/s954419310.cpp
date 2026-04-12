#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

int N;
int S[111111];

signed main(){
	cin>>N;
	rep(i,N)cin>>S[i];

	int ans=0;
	for(int D=1;D<N;D++){
		if((N-1)%D==0){
			int s=0;
			for(int j=1;j*D<N-1-j*D;j++){
				s+=S[j*D]+S[N-1-j*D];
				chmax(ans,s);
			}
		}
		else{
			int s=0;
			for(int j=1;j*D<N&&N-1-j*D>D;j++){

				s+=S[j*D]+S[N-1-j*D];
				chmax(ans,s);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}