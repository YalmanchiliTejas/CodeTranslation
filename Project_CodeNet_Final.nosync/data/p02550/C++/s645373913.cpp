#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


ll n,x,mod;

map<ll,ll> A;
map<ll,ll> Ai;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>x>>mod;

    A[1] = x;
    ll start = -1, end = -1;
    
    for (ll i=2; ;i++) {
	A[i]=A[i-1]*A[i-1]%mod;
	if (Ai.count(A[i])) {
	    start = Ai[A[i]];
	    end = i;
	    break;
	} else {
	    Ai[A[i]] = i;
	}
    }



    
    // watch(start);
    // watch(end);
    // for (int i=1; i<=end; i++) {
    // 	cout<<A[i]<<" ";
    // }
    // cout<<endl;


    if (n < start) {
	ll res = 0;
	for (int i=1; i<=n; i++) {
	    res += A[i];
	}
	out(res);
    }

    ll cycle = 0;
    vector<ll> v;
    for (int i=start; i<end; i++) {
	cycle += A[i];
	v.push_back(A[i]);
    }

    ll len = end-start;
    ll iters = (n-(start-1))/len;


    ll res = 0;
    for (int i=1; i<start; i++) {
	res += A[i];
    }

    res += iters*cycle;

    ll at = start + len*iters;
    ll todo = n - at + 1;

    for (int i=0; i<todo; i++) {
	res += v[i];
    }

    cout<<res<<endl;
    return 0;
}
