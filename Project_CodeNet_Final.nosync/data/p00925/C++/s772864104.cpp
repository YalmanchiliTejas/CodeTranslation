#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=1000000007;
ll MOD=998244353;
int inf=1000001000;
ll INF=100000000000000000;


int main() {
    string s;
    cin >> s;
    vector<int> a(0);
    int o=1,b=s[0]-'0';
    rep(i,s.size()/2){
        int u=s[2*i]-'0';
        char t=s[2*i+1];
        o*=u;
        if (t=='+') {a.push_back(o);o=1;}
    }
    int r=s[s.size()-1]-'0';
    a.push_back(o*r);
    int ans=0;
    for(int i:a) ans+=i;
    rep(i,s.size()/2){
        int u=s[2*i+2]-'0';
        char t=s[2*i+1];
        if (t=='+') b+=u;
        else b*=u;
    }
    int e;
    cin >> e;
    if (e==ans && e==b) cout << "U" << endl;
    else if (e==ans) cout << "M" << endl;
    else if (e==b) cout << "L" << endl;
    else cout << "I" << endl;
}

