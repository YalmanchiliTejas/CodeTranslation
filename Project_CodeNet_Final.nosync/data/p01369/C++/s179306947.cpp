#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define fin(ans) cout<<(ans)<<endl
#define STI(s) atoi(s.c_str())
#define mp(p,q) make_pair(p,q)
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(),a.end())
#define Rort(a) sort(a.rbegin(),a.rend())
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const int P = 1000000007;
const int INF = INT_MAX;
const long long LLINF = 1LL<<60;
//g++ -std=c++1z temp.cpp
//./a.out






int main(void){ios::sync_with_stdio(false);cin.tie(0);
///////////////////////////////////////////////////////
set<char> right,left;
right.insert('y');
right.insert('u');
right.insert('i');
right.insert('o');
right.insert('p');
right.insert('h');
right.insert('j');
right.insert('k');
right.insert('l');
right.insert('n');
right.insert('m');

while(1){
int ans=0;
string s;

cin >>s;
if(s == "#"){
    break;
}
rep(i,s.size()){
  if(right.find(s[i])!=right.end()){
      s[i] = '%';
    }
  else{
      s[i] = '$';
  }         
}

for(int i=1;i<s.size();i++){
    if(s[i-1]!=s[i]){
        ans ++;
    }
    else{
        ans =ans;
    }
    
}
cout << ans << endl;


}





///////////////////////////////////////////////////////
return 0;}
