#include<bits/stdc++.h>
using namespace std;

#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return
#define lb(v,n) lower_bound(v.begin(),v.end(),n)
#define ub(v,n) upper_bound(v.begin(),v.end(),n)
#define mae(v) max_element(v.begin(),v.end())
#define mie(v) min_element(v.begin(),v.end())
#define INF 0x7FFFFFFF
#define mod 1000000007
#define fir first
#define sec second
typedef long long ll;
////////////////////////////////////////////////////////////

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,0,n) cin >> a[i];
	vsort(a);
	deque<ll> deq;
	rep(i,0,n) deq.push_back(a[i]);
	deque<ll> b;
	b.push_back(deq.front());
	deq.pop_front();
	ll i = 0;
	while( deq.size() > 0 ){
		if( deq.size() >= 2 ){
			if( i % 2 == 0 ){
				ll fr = deq.back();
				deq.pop_back();
				ll ba = deq.back();
				deq.pop_back();
				b.push_back( ba );
				b.push_front(fr );
			}
			else{
				ll fr = deq.front();
				deq.pop_front();
				ll ba = deq.front();
				deq.pop_front();
				b.push_back( ba );
				b.push_front(fr );
			}
		}
		else{
			if( i % 2 == 0 ){
				ll fr = deq.back();
				deq.pop_back();
				b.push_front( fr );
			}
			else{
				ll fr = deq.front();
				deq.pop_front();
				b.push_front( fr);
			}
		}
		i++;
	}
	ll cnt = 0;
	ll bef = b.front();
	b.pop_front();
	while( b.size() > 0 ){
		cnt += abs( bef - b.front() );
		bef = b.front();
		b.pop_front();
	}
	ll ans1 = cnt;
	rep(i,0,n) deq.push_back(a[i]);
	b.push_front(deq.back());
	deq.pop_back();
	
	i = 0;
	while( deq.size() > 0 ){
		if( deq.size() >= 2 ){
			if( i % 2 ){
				ll fr = deq.back();
				deq.pop_back();
				ll ba = deq.back();
				deq.pop_back();
				b.push_back( ba );
				b.push_front(fr );
			}
			else{
				ll fr = deq.front();
				deq.pop_front();
				ll ba = deq.front();
				deq.pop_front();
				b.push_back( ba );
				b.push_front(fr );
			}
		}
		else{
			if( i % 2 ){
				ll fr = deq.back();
				deq.pop_back();
				b.push_front( fr );
			}
			else{
				ll fr = deq.front();
				deq.pop_front();
				b.push_front( fr);
			}
		}
		i++;
	}
	cnt = 0;
	bef = b.front();
	b.pop_front();
	while( b.size() > 0 ){
		cnt += abs( bef - b.front() );
		bef = b.front();
		b.pop_front();
	}
	
	cout << max ( cnt , ans1 ) << endl;

	ret 0;
}
