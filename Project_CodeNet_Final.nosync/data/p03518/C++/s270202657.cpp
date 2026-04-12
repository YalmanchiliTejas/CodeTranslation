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


void k_swap(vector<int>& v,int k){
    int n=v.size();
    for(int i=k;i<n;++i)swap(v[i],v[i-k]);
    //rep(i,n)cout<<v[i]<<" ";
    //cout<<endl;
}

bool sorted(vector<int>& v){
    int n=v.size();
    rep(i,n-1)if((v[i+1]-v[i]+n)%n!=1)return false;
    return true;
}
int main(){
    vector<int> ans;
    int n;
    cin>>n;
    vector<int> p(n);
    rep(i,n)cin>>p[i];
    int k=0;
    while(!sorted(p)){
        if(p[0]!=0&&p[n-1]!=0&&p[n-1]>p[0]){
            k_swap(p,n-1);
            ans.push_back(n-1);
        }
        k_swap(p,1);
        ans.push_back(1);
    }
    while(p[0]!=0){
        k_swap(p,1);
        ans.push_back(1);
    }
    cout<<ans.size()<<endl;
    for(auto e : ans)cout<<e<<endl;
    return 0;
}