#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forna(i,a,n) for(int i =a; i < n; i++)
#define fornd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push
#define fi first
#define se second
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long int unsigned lliu;
typedef long long int lli;
typedef pair<lli,lli> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

int main(){
    string s;
    int a=0;
    cin>>s;
    forn(i, s.size()){
        if(s[i]=='A')
            a++;
    }
    if(a==0 || a==3){
        cout<<"No\n";
    } else
        cout<<"Yes\n";
}