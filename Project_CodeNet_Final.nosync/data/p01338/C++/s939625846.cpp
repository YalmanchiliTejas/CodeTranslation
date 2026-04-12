#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define mp(a,b) make_pair((a),(b))
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
//template<typename T> using vec=std::vector<T>;

const int INF=1<<30;
const long long int INF_=1LL<<58;
const double EPS=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
	os << "[";
	for (const auto &v : vec) {
		os << v << ",";
	}
	os << "]";
	return os;
}

const int point[]={0,60,70,80},mask=3;
int memo[5][2<<8],grid[5][5];

int DFS(int y,int b){
	int &res=memo[y][b];
	if(res!=-1) return res;
	
	int cnt[5];
	cnt[0]=b&mask;
	cnt[1]=(b&mask)+((b>>2)&mask);
	cnt[2]=((b>>2)&mask)+((b>>4)&mask);
	cnt[3]=((b>>4)&mask)+((b>>6)&mask);
	cnt[4]=(b>>6)&mask;
	if(y==4){
		int score=0;
		if(grid[y][0]!=-1) score+=point[(grid[y][0]+cnt[0])%4];
		if(grid[y][1]!=-1) score+=point[(grid[y][1]+cnt[1])%4];
		if(grid[y][2]!=-1) score+=point[(grid[y][2]+cnt[2])%4];
		if(grid[y][3]!=-1) score+=point[(grid[y][3]+cnt[3])%4];
		if(grid[y][4]!=-1) score+=point[(grid[y][4]+cnt[4])%4];
		return res=score;
	}

	rep(i,0,4){
		rep(j,0,4){
			rep(k,0,4){
				rep(l,0,4){
					int score=0;
					if(grid[y][0]!=-1) score+=point[(grid[y][0]+cnt[0]+i)%4];
					if(grid[y][1]!=-1) score+=point[(grid[y][1]+cnt[1]+i+j)%4];
					if(grid[y][2]!=-1) score+=point[(grid[y][2]+cnt[2]+j+k)%4];
					if(grid[y][3]!=-1) score+=point[(grid[y][3]+cnt[3]+k+l)%4];
					if(grid[y][4]!=-1) score+=point[(grid[y][4]+cnt[4]+l)%4];
					res=max(res,DFS(y+1,i+(j<<2)+(k<<4)+(l<<6))+score);
				}
			}
		}
	}

	return res;
}

void Solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		fill_n((int*)memo,5*(2<<8),-1);
		rep(y,0,5){
			rep(x,0,5){
				cin >> grid[y][x];
				--grid[y][x];
			}
		}
		
		cout << DFS(0,0) << endl;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	Solve();
	return 0;
}