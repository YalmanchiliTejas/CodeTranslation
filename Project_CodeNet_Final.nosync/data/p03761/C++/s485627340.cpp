// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cpp,赤波線出るけどコンパイルできる

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,d,n,maxi=0,f=0,mini=INF,sum=0;
    ll w,h,x,y,k;
    //string str[3];
	cin>>n;
    vector<string> s(n);
    rep(i,n) cin>>s[i];
    map<char,ll> m[n];
    set<char> c;
    //rep(i,n) cin>>s[i];
    rep(i,n)rep(j,s[i].length()){
        m[i][s[i][j]]++;
        c.insert(s[i][j]);
    }
    //cout<<"a";

    map<char,ll> ans;
    for(auto itr=c.begin();itr!=c.end();++itr){
        ans[*itr] = INF;
    }
    for(auto itr=c.begin();itr!=c.end();++itr){
        rep(i,n) ans[*itr]=min(ans[*itr],m[i][*itr]);
    }
    vector<char> answer;
    for(auto itr=c.begin();itr!=c.end();++itr){
        rep(i,ans[*itr]) answer.push_back(*itr);
    }
    sort(all(answer));
    //answer.erase(answer.begin());
    rep(i,answer.size()) cout<<answer[i];
    ln; 

    return 0;
}

