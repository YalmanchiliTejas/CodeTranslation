#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;

void Main(){
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    int tot = 0;

    rep(i, h) {
        cin >> a[i];
        rep(j, w){
            if(a[i][j] == '#') tot ++;
        }
    }
    
    if(tot == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl; 
    
    return;
}

int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}