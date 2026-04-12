#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <list>
#include <numeric>
#include <utility>
#include <ctime>
#define INF 100000000
#define LINF 9000000000000000000
#define mod 1000000007
 
#define rep(i,n) for(int i=0;i<int(n);i++)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair
#define MOD(x) (x%(mod))
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool debug=false;

/*---------------------------------------------------*/

int n,w,l,d;
string name[15];
pair<int,pair<int,string> > data[15];

int main(){
  bool ok=false;
  while(cin>>n){
    if(n==0)break;
    if(ok)cout<<endl;
    else ok=true;
    
    rep(i,n){
      cin>>name[i]>>w>>l>>d;
      data[i].first=w*3+d;
      data[i].second.first=n-i;
      data[i].second.second=name[i];
    }

    sort(data,data+n);reverse(data,data+n);
    
    rep(i,n){
      cout<<data[i].second.second<<","<<data[i].first<<endl;
    }
  }
}