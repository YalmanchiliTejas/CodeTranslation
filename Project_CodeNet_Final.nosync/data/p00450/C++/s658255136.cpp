#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <map>
#include <climits>
#include <sstream>
using namespace std;

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second
#define mkp make_pair

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
static const int INF=1<<24;

template <class T>
void initvv(vector<vector<T> > &v,int a,int b, const T  &t = T()){
	v.assign(a,vector<T>(b,t));
}

//v.erase(unique(v.begin(),v.end()),v.end());


int main(){
	int n;
	while(cin>>n,n){
		stack<pii> st;
		rep(i,n){
			int t;
			cin>>t;
			if(i==0) st.push(mkp(t,1));
			else if(i%2==1){
				pii tt=st.top();
				st.pop();
				if(tt.F!=t){
					st.push(mkp(t,tt.S+1));
				}
				else{
					// cout<<"afa\n";
					// cout<<t<<endl;
					st.push(tt);
					st.push(mkp(t,1));
				}
				while(st.size()>1){
					pii t1=st.top();
					st.pop();
					pii t2=st.top();
					st.pop();
					if(t1.F==t2.F){
						// cout<<"fafafaf"<<t1.F<<endl;
						st.push(mkp(t1.F,t1.S+t2.S));
					}
					else{
						st.push(t2);
						st.push(t1);
						break;
					}
				}
			}
			else{
				pii t1=st.top();
				st.pop();
				if(t1.F==t){
					// cout<<"hoge\n";
					st.push(mkp(t1.F,t1.S+1));
				}
				else{
					st.push(t1);
					st.push(mkp(t,1));
				}
				// cout<<"faga"<<endl;
			}
			// cout<<i<<" "<<st.top().F<<" "<<st.top().S<<endl;
		}
		int ans=0;
		while(!st.empty()){
			if(st.top().F==0){
				ans+=st.top().S;
			}
			st.pop();
		}
		cout<<ans<<endl;
	}
}