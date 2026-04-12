#include <bits/stdc++.h>
#include <stdio.h>
#include <numeric>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define repone(i,n) for(int i=1;i<(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define Rep(j,n) for(int j=0;j<(int)(n);++j)
#define Repo(j,o,n) for(int j=o;j<(int)(n);++j)
#define Repone(j,n) for(int j=1;j<(int)(n);++j)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define int long long
#define pb(a) push_back(a)
#define pbpair(a,b) push_back(make_pair(a,b))
#define MOD 1000000007
#define INF 9223372036854775807
#define pairint pair<int,int>
typedef pair< int , string> P;
//実装案　勝たなかった試合＆負けた試合のベクター　照準ソートして上から
int gcd( int x, int y ){ return y ? gcd(y, x%y) : x; }
bool pairCompare(const P& firstElof, const P& secondElof)
{
  if(firstElof.first!= secondElof.first)    return firstElof.first> secondElof.first;

else return false;
}
signed main() {
int x=0,y=0,z=0,w=0,n=0,m=0;
string k;
bool a=false;
while(1){

  std::cin >> x;
  if(x==0)return 0;
  if(a){
      std::cout << '\n';
  }
  std::vector< pair <int,string> > v(x);
  Rep(j,x){
      std::cin >> k;
    v[j].second=k;
    v[j].first=0;
std::cin >> y>>z>>w;
v[j].first=y*3+w;
    }

  sort(all(v),pairCompare);
  rep(i,x){
    std::cout << v[i].second<<","<<v[i].first<< '\n';
  }
if(!a)a=true;
}
}
