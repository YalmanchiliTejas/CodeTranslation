#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000

char tr,suit;
vector<char> num{'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

struct card{
	string s;
};

bool sorter(const card& a,const card& b){
	if((a.s[1]==tr&&b.s[1]==tr)||(a.s[1]==suit&&b.s[1]==suit)){
		return (find(all(num),a.s[0])-num.begin())>(find(all(num),b.s[0])-num.begin());
	}else{
		return ((a.s[1]==tr)||(a.s[1]==suit&&b.s[1]!=tr));
	}
}

int main(){
	cin.sync_with_stdio(false);
	while(1){
		cin>>tr;
		if(tr=='#')break;
		card board[4][22];
		rep(i,4)rep(j,13)cin>>board[i][j].s;
		int sum[2];
		memset(sum,0,sizeof(sum));
		int win=0;
		rep(j,13){
			suit=board[win][j].s[1];
			card cs[4];
			rep(i,4)cs[i]=board[i][j];
			sort(cs,cs+4,sorter);
			rep(i,4){
				if(cs[0].s==board[i][j].s){
					win=i;
					break;
				}
			}
			sum[win%2]++;
		}
		if(sum[0]>sum[1]){
			cout<<"NS "<<sum[0]-6<<endl;
		}else{
			cout<<"EW "<<sum[1]-6<<endl;
		}
	}
	return 0;
}