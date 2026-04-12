//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<numeric>
#include<bitset>
#include<limits>
#include<unordered_map>
#include<functional>
using namespace std;

#define rep(i,s,n) for(int i=s;i<n;i++)
#define dow(i,n,s) for(int i=n-1;i>=s;i--)
#define all(a) a.begin(),a.end()
#define Sort(a) sort(all(a))
#define Qsort(a,size) qsort(a,size,sizeof(*a),compare_int)
#define DEBUG
typedef pair<int,int> II;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;
bool compare_int(const void *a,const void *b) { return *(int *)a-*(int *)b; }
bool compare_by_second(II a,II b) { return a.second!=b.second?a.second<b.second:a.first<b.first; }

const int INF = 1e+9;
const int MAX_S = 17;

string s;
int ans,M = 0,L = 0;
vector<int> Mi;

//void solve();

int main() {
  cin>>s>>ans;

  rep(i,0,s.size()) {
    if(s[i] =='*') { Mi[Mi.size()-1] = Mi[Mi.size()-1]*(s[i+1]-'0'); i++; }
    else if('0' <= s[i] && s[i] <= '9') Mi.push_back(s[i] - '0');
  }
  rep(i,0,Mi.size()) M+=Mi[i];

  rep(i,0,s.size()) {
    if(s[i] == '*') { L*=(s[i+1] - '0'); i++; }
    else if(s[i] == '+') { L+=(s[i+1] - '0'); i++; }
    else L = (s[i] - '0');
  }

  //cout<<"M-->"<<M<<" , L-->"<<L<<endl;

  if(ans == M && ans == L) { cout<<"U"<<endl; return 0; }
  if(ans != M && ans != L) { cout<<"I"<<endl; return 0; }
  if(ans == M) { cout<<"M"<<endl; return 0; }
  cout<<"L"<<endl; return 0;

}

