#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cassert>
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FOREACH(i,c) for(__typeof((c).begin())i = (c).begin();i!=(c).end(); ++i)

//v4
int cond = 1;
string to_string(char c){return'\''+string(1,c)+'\'';}
string to_string(const string&s){return'"'+s+'"';}
string to_string(const char*s){return to_string((string)s);}
string to_string(bool b){return(b?"true":"false");}
string to_string(std::vector<bool>::reference&r){return to_string((bool)r);}
template<typename A,typename B>string to_string(const pair<A,B>&p){return"("+to_string(p.first)+", "+to_string(p.second)+")";}
template<typename A>string to_string(A v){int f=1;string r="{";for(auto x:v){if(!f){r+=", ";}f=0;r+=to_string(x);}r+="}";return r;}
template<typename A,typename B>string to_string(map<A,B>v){int f=1;string r="{";for(auto x:v){if(!f){r+=", ";}f=0;r+=to_string(x.first)+" -> "+to_string(x.second);}r+="}";return r;}
void __db(int i,const vector<string>&s){cerr<<endl;}
template<typename T,typename... A>void __db(int i,const vector<string>&s,T t,A... a){if(i)cerr<<", ";cerr<<s[i]<<" = "<<to_string(t);__db(i+1,s,a...);}

string __cl(string s){while(!s.empty()&&s[0]==' ')s.erase(0,1);while(!s.empty()&&s.back()==' ')s.pop_back();return s;}
vector<string>__vars(string s){vector<string>r;s+=",";string n="";int d=0;for(auto x:s)if(x==','&&d==0){if(!n.empty())r.push_back(__cl(n));n="";}else{n+=x;if(x=='('||x=='[')d++;else if(x==')'||x==']')d--;}return r;}
#define DB(...){if(cond){cerr<<"Line:"<<__LINE__<<" ";__db(0,__vars(#__VA_ARGS__),__VA_ARGS__);}}


int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a == b) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

    return 0;
}