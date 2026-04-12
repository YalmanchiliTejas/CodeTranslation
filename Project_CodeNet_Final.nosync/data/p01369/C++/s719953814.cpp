#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


void solve(string s){
    set<int> st{0,1,2,3,4,5,6,16,17,18,19,21,22,23,25};
    int ans=0;
    int n=s.size();
    rep(i,n-1){
        if(st.count(s[i]-'a')^st.count(s[i+1]-'a'))++ans;
    }
    cout<<ans<<endl;
}
int main(){
    string s;
    while(cin>>s,s!="#")solve(s);
    return 0;
}
