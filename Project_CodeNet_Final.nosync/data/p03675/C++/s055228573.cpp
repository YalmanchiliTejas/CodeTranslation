#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    deque<ll> dq;
    ll n;
    cin >> n;
    ll a;
    for(int i=0;i<n;i++){
    	cin >> a;
    	if(i&1){
    		dq.push_front(a);
    	}else{
    		dq.push_back(a);
    	}
    }
    if(n%2 == 0){
    	while(!dq.empty()){
    		cout << dq.front() << " ";
    	    dq.pop_front();
    	}
    }else{
    	while(!dq.empty()){
    		cout << dq.back() << " ";
    	    dq.pop_back();
    	}
    }
    cout << endl;
    return 0;
}
