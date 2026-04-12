#include<bits/stdc++.h>

using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using vs=vector<string>;
using li=list<int>;
using lil=list<ll>;
using lis=list<string>;
using fli=forward_list<int>;
using fll=forward_list<ll>;
using fls=forward_list<string>;
using si=stack<int>;
using sl=stack<ll>;
using ss=stack<string>;
using qi=queue<int>;
using ql=queue<ll>;
using qs=queue<string>;
using pqi=priority_queue<int>;
using pql=priority_queue<ll>;
using pqs=priority_queue<string>;
using dqi=deque<int>;
using dql=deque<ll>;
using dqs=deque<string>;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, a, n) for(int i = (n); i < (a); i++)
#define repr(i, n) for(int i = (n); i >= 0; i--)
#define repr2(i, a, n) for(int i = (n); i >= (a); i--)

template<typename T,typename U>
void Inparray(T &f,U n){for(int i=0;i<n;i++) cin>>f[i];}

template<typename T,typename U>
void Printarray(T f,U n){for(int i=0;i<n;i++) i!=n ? cout<<f[i]<<" " : cout<<f[i];}
template<typename T,typename U>
void Printarray2(T f,U n){for(int i=0;i<n;i++) cout<<f[i]<<endl;}
template<typename T,typename U,typename V>
void Printarray3(T f,U a,V b){
  rep(i,a){
    rep(j,b){
      cout<<f[i][j];
    }
    cout<<endl;
  }
}
template<typename T,typename U>
void Printarray4(T f,U n){
  rep(i,n){
    rep(j,n){
      cout<<f[i][j];
    }
    cout<<endl;
  }
}

void flagfunc(bool flag,string A,string B){flag ? cout<<A<<endl : cout<<B<<endl;}
void flag2func(bool flag){flag ? cout<<"Yes"<<endl : cout<<"No"<<endl;}
void flag3func(bool flag){flag ? cout<<"YES"<<endl : cout<<"NO"<<endl;}

int main(){
  cin.tie(nullptr);ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  string s;cin>>s;
  int a=0,b=0;
  rep(i,s.size()){
    if(s[i]=='A')a++;
    if(s[i]=='B')b++;
  }
  flag2func(!(a==0 || b==0));
}
