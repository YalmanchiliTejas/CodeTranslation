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


void query(int s,int t){
    cout<<"? "<<s<<" "<<t<<endl;
}
int main(){
    int n,s,t;
    cin>>n>>s>>t;
    int d;
    query(s,t);
    cin>>d;
    vector<int> ds(n+1),dt(n+1);
    vector<int> a;
    rep(i,n){
        if(i+1==s)continue;
        query(s,i+1);
        cin>>ds[i+1];
        query(i+1,t);
        cin>>dt[i+1];
        if(ds[i+1]+dt[i+1]==d)a.push_back(i+1);
    }

    sort(a.begin(),a.end(),[&](int x,int y){
        return ds[x]<ds[y]; 
    });
    vector<int> ans;
    ans.push_back(s);
    for(auto e : a){
        int cur=ans.back();
        query(cur,e);
        int x;
        cin>>x;
        if(ds[cur]+x+dt[e]==d)ans.push_back(e);
        else continue;
    }
    cout<<"! ";
    for(auto e : ans){
        cout<<e;
        if(e!=ans.back())cout<<" ";
    }
    cout<<endl;
    return 0;
}
