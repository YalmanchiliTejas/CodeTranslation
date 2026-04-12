#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define each(a,x) for(auto a : (x))
#define all(a) (a).begin(),(a).end()
#define chmin(a,b) ((a) = min((a),(b)))
#define chmax(a,b) ((a) = max((a),(b)))
#define in_range(x,l,r) ((l)<=(x) && (x)<(r))
#define fs first
#define sc second
#define pb push_back
#define sz size() 
#define MP make_pair
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

const static int INF = 1e8;
const static D EPS = 1e-8;

int main(){
  int h,w;
  cin >> h >> w;

  int r=0;
  rep(i,h){
    string s;
    cin >> s;
    int nl=w, nr=0;
    rep(j,w){
      if(s[j] == '#'){
	chmin(nl,j);
	chmax(nr,j);
      }
    }

    if(nl != r){
      cout << "Impossible" << endl;
      return 0;
    }
    r = nr;
  }

  cout << "Possible" << endl;
  return 0;
}
