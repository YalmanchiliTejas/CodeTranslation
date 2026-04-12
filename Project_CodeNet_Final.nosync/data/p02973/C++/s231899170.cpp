#include<iostream>
#include<string>
#include<cstdio>
#include <cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back

void Yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
 
void No(){
	cout<<"No"<<endl;
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int N; cin >> N;
    int A[100100];
    rep(i, N) {
        int a;
        cin >> a;
        A[i] = (-1) * a;
    }
    int ans = 0;
    set<int> b;
    map<int, int> mp;
    b.insert(A[0]);
    mp[A[0]] ++;
    ans ++;
    rep1(i, N - 1) {
        auto ite = b.upper_bound(A[i]);
        if(ite == b.end()) {
            b.insert(A[i]);
            mp[A[i]] ++;
            ans ++;
        } else {
            if(mp[*ite] != 1) {
                mp[*ite] --;
            } else if(mp[*ite] == 1) {
                b.erase(ite);
                mp[*ite] = 0;
            }
            b.insert(A[i]);
            mp[A[i]] ++;
        }
    }
    cout << ans << endl;
	return 0;
}
