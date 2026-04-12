#include<bits/stdc++.h>
using namespace std;
 
#define cinsc ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOR(i,k,n)  for(int64 i=k;i<(int64)n;i++)
#define FORr(i,k,n)  for(int64 i=(int64)k;i>=n;i--)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FOREACHr(it, l) for (auto it = l.rbegin(); it != l.rend(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define SQ(x) ((x)*(x))
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//ONLINE_JUDGE   LOCAL
 
int64 powr(int64 x,int64 y,int64 p)  
{  
    int res = 1;    
    x = x % p; 
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % p;   
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 
 
void  in_o(){
#ifndef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cinsc;
}

int main(){
//	in_o();
	int h,w;
	bool flag=false;
	cin>>h>>w;
	string s[h];
	FOR(i,0,h){
		cin>>s[i];
	}
	FOR(i,0,h){
		flag=false;
		FOR(j,0,w){
			if(s[i][j]=='#') flag=true;
		}
		if(flag) continue;
		FOR(j,0,w){
			s[i][j]='x';
		}
	}
	
	FOR(i,0,w){
		flag=false;
		FOR(j,0,h){
			if(s[j][i]=='#') flag=true;
		}
		if(flag) continue;
		FOR(j,0,h){
			s[j][i]='x';
		}
	}

	FOR(i,0,h){
		flag=false;
		FOR(j,0,w){
			if(s[i][j]!='x') cout<<s[i][j],flag=true;
		}
		if(flag) cout<<endl;
	}

	return 0;
}