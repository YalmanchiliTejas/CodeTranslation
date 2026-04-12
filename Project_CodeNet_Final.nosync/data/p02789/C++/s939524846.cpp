#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef priority_queue<int> pqi;
typedef priority_queue<int, vi, greater<int>> mpqi;

#define IOS std::ios::sync_with_stdio(false); cin.tie(0);
#define F0R(i,a) for(int i = 0; i < a; i++)
#define R0F(i,a) for(int i = a - 1; i >= 0; i--)
#define S0RT(a,n) sort(a, a + n)
#define pb push_back
#define mp make_pair

const int MOD = 1000000007;
const ll INF = 1000000000000000000;
const ld PI = 4*atan((ld)1);

/* NOTES TO SELF:
    Int overflow? Use all ll if in doubt.
    Edge cases? (n = 1, n = 0)
*/

int n, m;

int main(){
    IOS;
    cin >> n >> m;
    if(n == m) cout << "Yes";
    else cout << "No";    
    return 0;
}