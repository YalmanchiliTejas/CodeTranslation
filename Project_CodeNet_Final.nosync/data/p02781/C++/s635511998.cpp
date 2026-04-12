#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const ll MOD = (ll)1e9 + 7 ;
const int N = (int)1e4 + 10;

string s;
int k; int n;

int dp[N][100][2];

int rec(int id = 0, int cnt = 0, int lrge = 1){
  	//cout << id << " " << cnt << " " << lrge << '\n';
    if( cnt > k) return 0;
    if( id == n){
        if( cnt == k) 
            return 1;
        else return 0;
    }
  	//cout << "YES ";
    auto & res = dp[id][cnt][lrge];
    if( res != - 1)
        return res;
    res = 0;
  	//cout << "YY \n";
    int LMT;
    if( lrge == 1)
        LMT = s[id] - '0';
    else 
        LMT = 9;
  	//cout << LMT << '\n';
    for(int j = 0; j <= LMT; ++j){
      	//cout << id << " " << j << '\n';
        int ncnt = cnt;
        int nlrge = lrge;
        if( lrge and j < LMT ) nlrge = 0; //the number is smaller now
        if( j ) ncnt++;
        if( ncnt <= k ) res += rec(id + 1, ncnt, nlrge);
    }
    return res;
}

void solve(){
    cin >> s;
    cin >> k;
    n = s.size();
  	//cout << s << " " << n << '\n'; 
    memset(dp, -1, sizeof dp);
    cout << rec() << '\n';
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    //int t; cin >> t;
    //while(t--)
        solve();
}