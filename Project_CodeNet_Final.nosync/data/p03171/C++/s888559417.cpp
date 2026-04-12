#include <iostream>
#include <bits/stdc++.h>
#define t97 1000000007

using namespace std;
typedef long long ll;

void dm(vector<vector<ll> >& m) {
    for(ll i = 0; i < m.size(); i++) {
        for(ll j = 0; j < m[i].size(); j++) {
            if(j != m[i].size()-1) {
                cout << m[i][j] << " ";
            } 
            else {
                cout << m[i][j] << endl;
            }
        }
    }
}

void dv(vector<ll>& v) {
    for(ll i = 0; i < v.size()-1; i++) {
        cout << v[i]<<" ";
    }
    cout << v[v.size()-1]<<endl;
}

void swap(ll& a, ll& b) {
    ll temp = a;
    a = b;
    b = temp;
}

ll minval(ll a, ll b) {
    if(a < b) {
        return a;
    }
    return b;
}

ll maxval(ll a, ll b) {
    if(a > b) {
        return a;
    }
    return b;
}

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

ll powmod(ll a, ll b, ll mod){
    if(b == 0)return 1;
    if(b%2 == 0){
        ll c = powmod(a,b/2, mod);
        return (c*c)%mod;
    }
	else{
        return (a*powmod(a,b-1, mod))%mod;
    }
}

ll modInverse(ll A,ll M)
{
    return powmod(A,M-2,M);
}

pair<ll, ll> getValues(ll player, vector<ll>& v, ll start, ll end, vector<vector<pair<ll, ll> > >& dp) {
	pair<ll, ll> ans, max1, max2;
	max1.first = max2.first = ans.first = 0;
	max1.second = max2.second = ans.second = 0;
	if(start > end) {
		return ans;
	}
	if(dp[start][end].first != -1 && dp[start][end].second != -1) {
		return dp[start][end];
	}
	if(player == 0) {
		max1 = getValues(player^1, v, start+1, end, dp);
		max1.first += v[start];
		max2 = getValues(player^1, v, start, end-1, dp);
		max2.first += v[end];
		if(max1.first > max2.first) {
			dp[start][end] = max1;
			return max1;
		}
		else if(max1.first < max2.first) {
			dp[start][end] = max2;
			return max2;
		}
		else {
			if(max1.second < max2.second) {
				dp[start][end] = max1;
				return max1;
			}
			else {
				dp[start][end] = max2;
				return max2;
			}
		}
	}
	else {
		max1 = getValues(player^1, v, start+1, end, dp);
		max1.second += v[start];
		max2 = getValues(player^1, v, start, end-1, dp);
		max2.second += v[end];
		if(max1.second > max2.second) {
			dp[start][end] = max1;
			return max1;
		}
		else if(max1.second < max2.second) {
			dp[start][end] = max2;
			return max2;
		}
		else {
			if(max1.first < max2.first) {
				dp[start][end] = max1;
				return max1;
			}
			else {
				dp[start][end] = max2;
				return max2;
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin); 
//    freopen("output.txt", "w", stdout);
	ll n;
	cin>>n;
	vector<ll> v(n);
	pair<ll, ll> p;
	p.first = -1;
	p.second = -1;
	vector<pair<ll, ll> > tempv(n, p);
	vector<vector<pair<ll, ll> > > dp;
	for(ll i = 0; i < n; i++) {
		dp.push_back(tempv);
	}
	for(ll i = 0; i < n; i++) {
		cin>>v[i];
	}	
	pair<ll, ll> ans = getValues(0, v, 0, n-1, dp);
	cout << ans.first - ans.second << endl;
	
    return 0;
}