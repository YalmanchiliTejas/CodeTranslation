// #pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
#define fou(i,a,n) for(int i=a;i<n;i++)
#define fod(i,a,n) for(int i=n-1;i>=a;i--)
#define rep(n) fou(_,0,n)
#define tra(a,x) for(auto& a : x)
#define elif(c) else if(c)

#define emb emplace_back
#define pub push_back
#define pob pop_back
#define me min_element
#define Me max_element
#define mp make_pair
#define fi first
#define se second
#define siz(xs) ((int)(xs).size())
#define all(xs) xs.begin(),xs.end()
#define lla(xs) xs.rbegin(),xs.rend()
#define sortup(xs) sort(all(xs))
#define sortdown(xs) sort(lla(xs))
template<class C>void mini(C &a,C b){a=min(a,b);}
template<class C>void maxi(C &a,C b){a=max(a,b);}
#define in(T,...) T __VA_ARGS__;_cin(__VA_ARGS__)
#define out(...) _cout(__VA_ARGS__);
void _cin(){}template<class Head,class...Tail>void _cin(Head&&head,Tail&&...tail){cin>>head;_cin(forward<Tail>(tail)...);}
void _cout(){}template<class Head,class...Tail>void _cout(Head&&head,Tail&&...tail){cout<<head<<endl;_cout(forward<Tail>(tail)...);}
template<class Type>void _cinvec(Type t,int n){}template<class Type,class Head,class...Tail>void _cinvec(Type t,int n,Head&&head,Tail&&...tail){rep(n){cin>>t;head.eb(t);}_cinvec(t,n,forward<Tail>(tail)...);}

#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define VVI vector<VI>
#define VVD vector<VD>
#define VVS vector<VS>

// #define int int64_t
// #define double long double

// map
// 横並びcout




signed main(){
  // in(int,a,b,c);
  // string ans;
  // if(c!=max({a,b,c})&&c!=max({a,b,c})) ans="Yes";
  // else ans="No";
  // out(ans);

  in(int,N);
  in(string,S);
  in(int,K);
  char c=S[K-1];
  fou(i,0,N){if(S[i]!=c)cout<<'*';else cout<<S[i];}
  cout<<endl;
}