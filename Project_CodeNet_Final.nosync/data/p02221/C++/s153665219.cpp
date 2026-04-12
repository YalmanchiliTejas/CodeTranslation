#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

int N;
string S;
vector<vector<vector<int>>> ps;
int res[300010],res2[300010];

int win(int i,int j){
	if(i>j)swap(i,j);
	return S[j-i-1]=='0'?i:j;
}

void dfs(int k,int d,int v){
	if(d==N){
		res[v]=ps[d][k][0];
		return ;
	}

	int sz=ps[d][k].size();
	/*dbg(k); dbg(d); dbg(v);
	rep(i,sz){
		cout<<ps[d][k][i]<<" ";
	}
	cout<<endl;
	cout<<"---"<<endl;*/

	{
		vector<int> tmp;
		for(int i=0;i<sz-1;i+=2){
			tmp.push_back(win(ps[d][k][i],ps[d][k][i+1]));
		}
		ps[d+1][2*k]=tmp;
	}
	dfs(2*k,d+1,v);
	{
		vector<int> tmp;
		tmp.push_back(win(ps[d][k][0],ps[d][k][sz-1]));
		for(int i=1;i<sz-2;i+=2){
			tmp.push_back(win(ps[d][k][i],ps[d][k][i+1]));
		}
		ps[d+1][2*k+1]=tmp;
	}
	dfs(2*k+1,d+1,v|(1<<d));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N>>S;
  vector<int> P(1<<N);
  rep(i,1<<N){
  	cin>>P[i];
  	P[i]--;
  }
  ps.resize(N+1);
  rep(i,N+1)ps[i].resize(1<<i);
  ps[0][0]=P;
  dfs(0,0,0);

  rep(i,1<<N){
  	cout<<res[((1<<N)-i+(1<<N))%(1<<N)]+1<<endl;
  }

  return 0;
}

