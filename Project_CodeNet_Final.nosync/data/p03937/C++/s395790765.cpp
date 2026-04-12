#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define F first
#define S second
const int N = 9;
vector<pii> v;
int n, m;
string S[9];
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> S[i];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(S[i][j]=='#') v.push_back({i, j});
    for(pii x:v) for(pii y:v) if(x.F>y.F && x.S<y.S) { cout << "Impossible"; return(0); }
    cout << "Possible";
}