#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

string s[10];
int main(){
    int h,w;
    cin>>h>>w;
    rep(i,h) cin>>s[i];
    rep(i,h-1)rep(j,w-1){
        if(s[i+1][j]=='#'&&s[i][j+1]=='#'){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}