#include <bits/stdc++.h>

using namespace std;

#define _overload3(_1,_2,_3,_4,name,...) name
#define _rep(i,n) _repi(i,0,n)
#define _repi(i,a,b) for(int i=a, i##_len=(b); i<i##_len; ++i)
#define _repis(i,a,b,s) for(int i=a, i##_len(b); i<i##_len; i+=s)
#define REP(...) _overload3(__VA_ARGS__,_repis,_repi,_rep,)(__VA_ARGS__)

#define REPR(i, n) for(int i = n;i >= 0;--i)
#define REPARR(i, v) for(int i = 0;i < v.size();++i)

#define YES(n) cout<<((n)?"YES":"NO")<<endl
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
#define yes(n) cout<<((n)?"yes":"no")<<endl
#define poss(n) cout<<((n)?"possible":"impossible")<<endl
#define Poss(n) cout<<((n)?"Possible":"Impossible")<<endl
#define POSS(n) cout<<((n)?"POSSIBLE":"IMPOSSIBLE")<<endl

int main(){
    string s;
    cin>>s;
    REP(i,s.size()-1){
        if(s.substr(i, 2)=="AC"){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
