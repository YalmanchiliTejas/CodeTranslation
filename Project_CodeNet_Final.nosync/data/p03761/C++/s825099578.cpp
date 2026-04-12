#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MA(i,j) make_pair(i,j)
#define PA pair<int,int>
#define PB push_back
#define PQ priority_queue<int>
#define PGQ priority_queue<int,vector<int>,greater<int> >
#define VE vector<int>
#define VP vector<PA>
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define MOD 1000000007
#define INF 1000000007
#define PI 3.14159265358979323846
using namespace std;
//
int N;
int cnt[26];
string S;
int main(){
  cin>>N;
  FOR(i,0,26){
    cnt[i]=INF;
  }
  FOR(i,0,N){
    cin>>S;
    int p[26];
    fill(p,p+26,0);
    FOR(j,0,(int)S.size()){
      p[S[j]-'a']++;
    }
    FOR(j,0,26){
      cnt[j]=min(cnt[j],p[j]);
    }
  }
  FOR(i,0,26){
    FOR(j,0,cnt[i]){
      char c='a'+i;
      cout<<c;
    }
  }
  return 0;
}
