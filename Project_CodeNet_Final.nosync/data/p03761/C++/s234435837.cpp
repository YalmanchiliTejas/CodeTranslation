#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int n;
    cin >> n;
    vector<int> a('z'-'a'+20,0);
    vector<vector<int>> v(n+10,vector<int>('z'-'a'+20,0));
    rep(i,n){
        string s;
        cin >> s;
        set<char> sc;
        rep(j,s.size()){
            sc.insert(s[j]);
            v[i][s[j]-'a']++;
        }
        for(auto u : sc){
            a[u-'a']++;
        }
    }
    string s = "";
    rep(i,a.size()){
        if(a[i]==n){
            int min1 = inf;
            rep(j,n){
                min1 = min(min1,v[j][i]);
            }
            rep(k,min1){
                s.push_back(i+'a');
            }
        }
    }
    sort(s.begin(),s.end());
    cout << s << endl;
    return 0;
}