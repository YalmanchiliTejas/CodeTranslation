#include<bits/stdc++.h>

#define reps(i,j,k) for(int i=(j);i<(k);i++)
#define rep(i,j) reps(i,0,j)
#define sc second
#define fs first
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int bd[10][10];

int W,H;
void dec(string s){
	int p=0,w=0,h=0;
	rep(i,s.length()){
		char c = s[i];
		if (c == 'b' ) bd[h][w++]=1;
		else if (c == '/') {w=0;h++;}
		else w+=c-'0';
	}
	W=w;
	H=h+1;
}

void enc(){
	rep(i,H){
		int cnt = 0;
		rep(j,W){
			if(bd[i][j]){
				if(cnt) cout << cnt;
				cout << 'b';
				cnt = 0;
			}
			else cnt++;
		}
		if(cnt) cout << cnt;
		if(i!=H-1)cout << "/";
	}
	cout << endl;
}
void pr(){
	rep(i,H){
		rep(j,W){
			cout << (bd[i][j] ? 'b' : '.');
		}
		cout << endl;
	}
}
int main(){
	int a,b,c,d;
	string s;
	for(;;){
		cin >> s;
		if(s[0] == '#') break;
		rep(i,10)rep(j,10) bd[i][j] = 0;
		cin >> a >> b >> c >> d;
		a--;b--;c--;d--;
		dec(s);
		swap(bd[a][b], bd[c][d]);
		enc();
	}
	return 0;
}