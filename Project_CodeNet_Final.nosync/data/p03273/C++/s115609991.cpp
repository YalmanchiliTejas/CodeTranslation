#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const ll mod=pow(10,9)+7;
const ll INF=pow(2,31)-1;
typedef pair<int,int> P;
typedef vector<int> vi;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll gcd(ll a , ll b){
	if(b == 0) return a;
	return gcd(b , a % b);	
}
ll lcm(ll a , ll b){
	ll g = gcd(a , b);
	ll lc = (a/g) * b;
	return lc;
}

int main(){
    ios::sync_with_stdio(false);
    int h,w;
    char a[105][105];
    cin >> h >> w ;
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    vector<int> cnt,cnt2;
    rep(i,h){
        if(a[i][0]!='.'){
            cnt.push_back(i);
        } else{
            int idx=0;
            rep(j,w){
                if(a[i][j]=='.') idx++;
            }
            if(idx!=w) cnt.push_back(i);
        }
    }
    rep(j,w){
        if(a[0][j]!='.'){
            cnt2.push_back(j);
        } else{
            int idx2=0;
            rep(i,h){
                if(a[i][j]=='.') idx2++;
            }
            if(idx2!=h) cnt2.push_back(j);
        }
    }
    for(auto i:cnt){
        for(auto j:cnt2){
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}