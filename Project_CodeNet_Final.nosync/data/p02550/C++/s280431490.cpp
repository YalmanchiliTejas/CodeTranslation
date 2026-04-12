#define _USE_MATH_DEFINES
 
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long long;
 
constexpr ll MOD = 1000000007;
 
#ifndef ONLINE_JUDGE
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " (" << x.first << " : " << x.second << ")" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "["; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "(" << obj.first << ", " << obj.second << ")"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print_sim_py(void) {cout << endl;}
template <class Head> void print_sim_py(Head&& head) {cout << head;print_sim_py();}
template <class Head, class... Tail> void print_sim_py(Head&& head, Tail&&... tail) {cout << head << " ";print_sim_py(forward<Tail>(tail)...);}

#define print(...) print_sim_py(__VA_ARGS__);
#else
#define print(...);
#endif

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll ans;
	ll n,x,m;

	cin >> n >> x >> m;
	
    vector<ll> sum_a(m+1,0);
	vector<ll> mem(m,0);

	ll sum = 0;

	ll first_i=0, final_i=0;
    for(ll i=0; i<n; i++){
		print(x)
		if(mem[x]){
			first_i = mem[x];
			final_i = i;
			break;
		}
		sum += x;
		mem[x] = i;
		sum_a[i+1] = sum;
        x = (x*x)%m;
	}

	ll times = 0;
	ll bsec = sum;
	ll sec = 0;
	ll asec = 0;
	ll md = 0;
	if(final_i!=first_i){
		times = (n-first_i)/(final_i - first_i);
		md = (n-first_i)%(final_i - first_i);
		
		//
		print(first_i, final_i)
		bsec = sum_a[first_i];
		sec = sum_a[final_i] - sum_a[first_i];
		asec = sum_a[first_i+md] - sum_a[first_i];
	}

	print(bsec, sec,asec, first_i,final_i, sum, times, md)

	ans = bsec + sec*times + asec;

    
    cout << ans << endl;
 
    return 0;
}
