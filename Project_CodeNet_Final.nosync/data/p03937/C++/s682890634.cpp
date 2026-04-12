#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;

int h,w;
vector<string> vs;
int dr[]={0,1,0,-1,0};


void rec2(int y,int x, int py, int px){
	if(y==h-1 && x==w-1){ return;}
	rep(i,2){
		int ny=y+dr[i],  nx=x+dr[i+1];
		if(py==ny && nx == px) continue;
		if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
		if(vs[ny][nx] == '#' && i<2){
			vs[ny][nx] = '@';
			rec2(ny, nx, y, x);
			break;
		}
	}
	
}


int main()
{

	//cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> h >>w;
	vs.resize(h);
	rep(i,h) cin >> vs[i];
	vs[0][0]='@';
	rec2(0,0,-1,-1);
	//for(auto x :vs) cout<<x <<endl;
	rep(i,h)rep(j,w) if(vs[i][j]=='#'){puts("Impossible");return 0;}
	puts("Possible");
	return 0;
}
