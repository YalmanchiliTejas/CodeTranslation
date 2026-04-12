#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

string s;

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> s;
    for(int i=0;i<s.lg-1;i++){
        if(s[i]=='A' && s[i+1]=='C'){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
