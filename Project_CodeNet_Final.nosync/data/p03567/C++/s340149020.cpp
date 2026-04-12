#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define preturn(X) cout<<X<<endl; return 0
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
//cout.setf(ios::fixed); cout.precision(18)



int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    rep(i,0,s.size()-1){
        if(s[i]=='A' && s[i+1]=='C'){
            preturn("Yes");
        }
    }
    preturn("No");
}