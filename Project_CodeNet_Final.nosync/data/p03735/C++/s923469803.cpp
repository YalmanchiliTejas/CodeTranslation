#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

const ll INF = (1ll << 60);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<pll> t(N);
    REP(i, N){
    	cin >> t[i].first >> t[i].second;
    	if(t[i].first > t[i].second) swap(t[i].first, t[i].second);
    }
    ll res = INF;

    ll rmi = INF, bmi = INF, rma = -1, bma = -1;
    ll mind, mand;
    REP(i, N){
    	if(rmi > t[i].first){
    		rmi = t[i].first;
    		mind = i;
    	}
    	rma = max(rma, t[i].first);
    	bmi = min(bmi, t[i].second);
    	if(bma < t[i].second){
    		bma = t[i].second;
    		mand = i;
    	}
    }
    res = min(res, (bma - bmi)*(rma - rmi));

    if(mind == mand){
    	cout << res << endl;
    }else{
    	ll mihaba = INF;
    	multiset<ll> st;
    	st.insert(t[mind].second);
    	st.insert(t[mand].first);
    	vector<pll> x;
    	REP(i, N){
    		if(i != mind && i != mand){
    			x.push_back(t[i]);
    			st.insert(t[i].first);
    		}
    	}
    	sort(x.begin(), x.end());

    	ll ue = *(--st.end());
    	ll shita = *(st.begin());
    	mihaba = min(mihaba, ue - shita);
    	REP(i, x.size()){
    		st.erase(st.find(x[i].first));
    		st.insert(x[i].second);
    		/*
    		for(auto xx :st) cout << xx << " ";
    		cout << endl;
    		*/
    		ue = *(--st.end());
    		shita = *(st.begin());
    		mihaba = min(mihaba, ue - shita);
    	}
    	res = min(res, (bma - rmi)*mihaba);
    }
    cout << res << endl;
    return 0;
}