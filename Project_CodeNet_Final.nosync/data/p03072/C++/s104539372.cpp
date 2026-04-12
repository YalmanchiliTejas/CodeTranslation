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
const int con = static_cast<const int>(1e6 + 5);
const int MOD = 1000000007;


int main (){
	FASTIO
#ifdef _online_judge
	freopen("input.txt" , "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    FOR(i,0,n) cin >> arr[i];
    int ans=0;
    FORd(i,n-1,-1){
        bool flag = true;
        FORd(j,i-1,-1){
            if(arr[j] > arr[i]){
                flag = false;
            }
        }
        if(flag) ans++;
    }
    cout << ans;
}
