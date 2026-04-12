//Finite Disappointment and Infinite Hope
#include <bits/stdc++.h>
using namespace std;
#define help ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.first<<","<<v.second<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    for(auto &x:c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
const ll N=2e5+5,MOD=1e9+7;
int main(){
help
    ll n,m;cin>>n>>m;
    if(n==m)cout<<"Yes";
    else cout<<"No";

}
