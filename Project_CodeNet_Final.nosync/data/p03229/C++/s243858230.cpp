#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
ll a[maxn];


ll get(deque<ll> qq) {
    int n = qq.size();
    ll res = 0;
    for (int i=0; i+1<n; i++) {
	res += abs(qq[i]-qq[i+1]);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }
    sort(a,a+n);

    if (n==1) out(0);
    
    ll ans = 0;
    {
	deque<ll> qq;
	int l=0; int r=n-1;
	bool flag=false;
	while (l<=r) {
	    if (flag) {
		qq.push_back(a[l++]);
	    } else {
		qq.push_back(a[r--]);
	    }
	    flag=!flag;
	}
	ll res = get(qq);
	ans = max(ans, res);

	for (int i=0; i<n; i++) {
	    res -= abs(qq[n-1]-qq[n-2]);
	    res += abs(qq[n-1]-qq[0]);
	    qq.push_front(qq[n-1]);
	    qq.pop_back();
	    ans = max(ans, res);
	}

	for (int i=0; i<n; i++) {
	    res -= abs(qq[0]-qq[1]);
	    res += abs(qq[0]-qq[n-1]);
	    qq.push_back(qq[0]);
	    qq.pop_front();
	    ans = max(ans, res);
	}
    }



    {
	deque<ll> qq;
	int l=0; int r=n-1;
	bool flag=true;
	while (l<=r) {
	    if (flag) {
		qq.push_back(a[l++]);
	    } else {
		qq.push_back(a[r--]);
	    }
	    flag=!flag;
	}
	ll res = get(qq);
	ans = max(ans, res);

	for (int i=0; i<n; i++) {
	    res -= abs(qq[n-1]-qq[n-2]);
	    res += abs(qq[n-1]-qq[0]);
	    qq.push_front(qq[n-1]);
	    qq.pop_back();
	    ans = max(ans, res);
	}
	for (int i=0; i<n; i++) {
	    res -= abs(qq[0]-qq[1]);
	    res += abs(qq[0]-qq[n-1]);
	    qq.push_back(qq[0]);
	    qq.pop_front();
	    ans = max(ans, res);
	}
    }




    cout<<ans<<endl;
    return 0;
}
