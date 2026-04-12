#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#define _debug
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sc(x) scanf("%d",&x)
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORd(i,a,b) for(int i=a;i>b;i--)
#define ff first
#define ss second
#define sz(x) x.size()
#define pb push_back
//#define _online_judge

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, //data type
        null_type, //
        less<int>, //
        rb_tree_tag, //red-black tree
        tree_order_statistics_node_update> new_data_set;

typedef pair<int,int> pii;
typedef vector<pii> vii;
const int con = static_cast<const int>(1e5 + 2);
const int MOD = 1000000007;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);

}


int main (){
	FASTIO
#ifdef _online_judge
	freopen("input.txt" , "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    int n;cin >> n;
    string s;cin >> s;
    int k;cin >> k;
    for(int i=0;i<n;i++){

        if(s[i] != s[k-1]) s[i] = '*';
    }
    cout << s;
    return 0;
}
