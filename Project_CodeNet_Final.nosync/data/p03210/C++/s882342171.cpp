#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define why(n,x) int n;while(cin >>n,n!=x)
#define iFOR(i,x,n)for(int i=x;i<n;i++)
#define unless(flg) if ( !(flg) )
#define read cin<<
#define echo cout<<
#define fin <<'\n'
#define __ <<" "<<
#define bash push_back
#define alles(x) x.begin(),x.end()
#define SWAP(a,b) ((a != b) && (a += b,b = a - b,a -= b))
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,-1,1,-1,1};
const int INF=1 << 30;
bool inside(int x,int y,int w,int h){
  return (x>=0 && y>=0 && x<w && y<h);}
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vit;
typedef map<string,int> mstit;
typedef priority_queue<int> pqit;
 
 
 
 
 
int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n;
  cin >>n;
  if(n==7||n==5||n==3) cout <<"YES\n";
  else cout <<"NO\n" ;
  

  return 0;
}
