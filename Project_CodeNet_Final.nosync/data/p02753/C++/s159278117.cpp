#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define re(i,n) for(ll i=0;i<n;++i)
#define ocut cout
#define ouct cout
#define itn int
struct Union{
  vector<int> par;
  Union(int a){
  par=vector<int>(a,-1);
  }
  int find(int a){
    if(par[a]<0){
      return a;
    }
    else{
      return par[a]=find(par[a]);
    }
  }
  bool same(int a,int b){
    return (find(a)==find(b));
  }
  int size(int a){
    return -par[find(a)];
  }
  void unite(int a,int b){
    int c=find(a),d=find(b);
    if(c==d)
      return;
    if(size(c)<size(d)){
      swap(c,d);
    }
    par[c]+=par[d];
    par[d]=c;
  }
};
int main(void){
    string s;
    cin >> s;
    if(s=="AAA"||s=="BBB")cout << "No";
    else cout << "Yes";
}
