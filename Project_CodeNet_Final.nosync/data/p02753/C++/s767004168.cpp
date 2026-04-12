#include <bits/stdc++.h>
using namespace std;
typedef long long in;
typedef pair<in,in> ii;
#define F first
#define S second
#define sqr(x) (x)*(x)
#define pb(x) push_back(x)
#define sz(x) (in)x.size()
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,x,y) for(in i=x;i<(y);++i)
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
/* start */

int main(){
    IOS;
    string s;
    cin >> s;
    in a=0,b=0;
    rep(i,0,sz(s)){
        if(s[i] == 'A'){
            a++;
        }
        else b++;
    }
    (a==0 or b==0) ? cout << "No\n" : cout << "Yes\n";
}