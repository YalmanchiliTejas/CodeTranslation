#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll r,w,c,unit;
ll i,n;
char s[500005];

bool solve(){
	cin >> s;
	n = strlen(s);
	if(strlen(s) == 1 && s[0] == '#')return false;
	bool ban[15][15];
	ll ix = 0,iy = 0;
	ll h , w;
	for(i=0;i<n;i++){
		if(s[i] == 'b'){
			ban[ix][iy] = true;
			iy++;
		}else if(s[i] >= '0' && s[i] <= '9'){
			for(int k=0;k<(s[i] - '0');k++){
				ban[ix][iy] = false;
				iy++;
			}
		}else if(s[i] == '/'){
			w = iy;
			iy = 0;
			ix ++;
		}
		
	}
	h = ix + 1;
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	ban[a-1][b-1] = false;
	ban[c-1][d-1] = true;
	i = 0;
	ll cnt = 0;
	char t[500005];
	ll num = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			//cout << ban[i][j] << " ";
		}
		//cout << endl;
	}
	a = 0;
	//cout << h << " " << w << endl;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(!ban[i][j]){
				a++;
			}else{
				if(a != 0)cout << a;
				cout << "b";
				a = 0;
			} 
		}
		if(a != 0){
			cout << a;
		}
		if(i != h-1){
			cout << "/";
			a = 0;
		}else{
			cout << endl;
		}
	}
	return true;
}
		
int main(){
	while(solve()){}
			
	return 0;
}
