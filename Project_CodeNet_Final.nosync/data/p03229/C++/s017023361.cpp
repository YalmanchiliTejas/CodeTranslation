#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
void dbg(){ cerr << "\n"; }  template <typename T,typename ...T2> 
void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
const int dr[]={0,1,0,-1,0};

int main(){
	int n;
	cin >>n;
	VI a(n);
	deque<int> dq;
	rep(i,n) cin >>a[i];
	sort(all(a));
	
	dq.push_back(a[0]);
	int l=1, r=n-1;
	rep(i, n){
		if(r<l) break;
		if(i%2==0){
			if(r>=l) dq.push_back(a[r--]);
			if(r>=l) dq.push_front(a[r--]);
		}else{
			if(r>=l) dq.push_back(a[l++]);
			if(r>=l) dq.push_front(a[l++]);
		
		}
	}
	//for(auto x :dq) printf("%d, ",x); puts("");
	ll sm =0;
	rep(i,n-1) sm += abs(dq[i] - dq[i+1]);
	
	dq.clear();
	dq.push_back(a.back());
	l=0, r=n-2;
	rep(i, n){
		if(r<l) break;
		if(i%2==1){
			if(r>=l) dq.push_back(a[r--]);
			if(r>=l) dq.push_front(a[r--]);
		}else{
			if(r>=l) dq.push_back(a[l++]);
			if(r>=l) dq.push_front(a[l++]);
		
		}
	}
	//for(auto x :dq) printf("%d, ",x); puts("");
	ll sm2 =0;
	rep(i,n-1) sm2 += abs(dq[i] - dq[i+1]);
	
	//dbg(sm ,sm2);
	
	cout << max(sm, sm2) <<"\n";
}

