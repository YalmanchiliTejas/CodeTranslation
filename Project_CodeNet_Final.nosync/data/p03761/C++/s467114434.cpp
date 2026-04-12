#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rrep(i,n) for(int i=1; i<=(int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

//const ll mod=1000000007;

int main() {
    int N;
    cin>>N;
    vi v(26,0);
    string s;
    cin>>s;
    rep(i,s.size()) {
        v[s[i]-'a']++;
    }
    rep(i,N-1) {
        string S;
        cin>>S;
        vi c(26,0);
        rep(j,S.size()) c[S[j]-'a']++;
        rep(j,26) {
            v[j]=min(v[j],c[j]);
        }
        rep(j,26) c[j]=0;
    }
    rep(i,26) {
        if(v[i]==0) continue;
        else {
            rep(j,v[i]) cout<<char(i+'a');
        }
    }
    cout<<endl;
}