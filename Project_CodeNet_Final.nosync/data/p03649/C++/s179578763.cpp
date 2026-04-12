// #includes {{{
#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

int calc(vector<long long> a){
	int N = a.size();
	int K = 0;
	while(1){
		/*
		cout<<"calc"<<endl;
		REP(i,N)cout<<a[i]<<" ";
		cout<<endl;
		*/
		int max_id = -1;
		int max_val = -INF;
		REP(i,a.size()){
			if(max_val < a[i]){
				max_val = a[i];
				max_id = i;
			}
		}
		if(max_val <= N-1)return K;
		K++;
		REP(i,a.size()){
			if(i == max_id)a[i] -= N;
			else a[i]++;
		}
	}
}

void solve(long long N, vector<long long> a){
	long long s = accumulate(ALL(a),0ll);
	vector<long long> r(a);
	REP(i,N)r[i]%=(N+1);
	int rsum_max = -INF;
	vector<long long> rsum_vec;
	REP(d,N+1){
		bool valid = false;
		vector<long long> r2(r);
		REP(i,N){
			r2[i] = (r[i] + d)%(N+1);
			if(r2[i] == N)valid = true;
		}
		if(!valid)continue;
		long long rsum = accumulate(ALL(r2),0ll);
		if(rsum>rsum_max){
			rsum_max = rsum;
			rsum_vec = r2;
		}
	}
	/*
	cout<<s<<" "<<rsum_min<<endl;
	REP(i,rsum_vec.size()){
		cout<<rsum_vec[i]<<" ";
	}
	cout<<endl;
	*/
	long long K = 0;
	if(s>=rsum_max){
		REP(i,N)K+=(a[i]-rsum_vec[i]);
		a = rsum_vec;
	}
	/*
	dump(K);
	REP(i,a.size()){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	*/
	K+=calc(a);
	cout<<K<<endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(N, a);
	return 0;
}
