//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<int, int> mii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vii;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define F first
#define S second
#define in insert
const int INF = 1e9 + 7;
int main(){
    int n; cin>>n;
    int ans=0;
    int ma = 0;
    for(int i = 0; i < n; i++){
        int t; cin>>t;
        ma = max(ma,t);
        if(t>=ma) ans++;
    }
    cout<<ans;
}