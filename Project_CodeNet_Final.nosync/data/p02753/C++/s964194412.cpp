#include<deque>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cassert>
#include<random>
#include<fstream>
#include<chrono>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define int          long long
#define ld           long double
#define pii          pair<int,int>
#define vi           vector<int>
#define pb           push_back
#define mp           make_pair
#define ff           first
#define ss           second
#define rep(i,s,e)   for(int i=(s);i<=(e);i++)
#define brep(i,s,e)  for(int i=(s);i>=(e);i--)
#define all(x)       (x).begin(),(x).end()
#define ball(x)      (x).rbegin(),(x).rend()
#define sz(x)        (int)x.size()
#define mem(x,y)     memset(x,y,sizeof(x))
#define VR46         ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);ifstream fin("ip.txt");ofstream fout("op.txt");
#define milf(x)      x.reserve(1LL<<14LL); x.max_load_factor(0.25); // less_equal
#define pbds         tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
mt19937              rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7;
const int INF = 0x3F3F3F3F3F3F3F3F;
ld EPS = 1e-12;

signed main()
{
    VR46 // GANDU TEST CASE BNALE
    // int t;cin>>t;rep(test,1,t)
    {
        string s;
        cin>>s;
        bool a = false, b = false;
        rep(i,0,2) s[i]=='A' ? a = true : b = true;
        if( a && b ) cout<<"Yes\n";
        else cout<<"No\n";
    }
}