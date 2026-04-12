#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#include <ctime>
#include <assert.h>
#include <chrono>
#include <random>
#include <numeric>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (ull)rng() % B;
}

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	while(1){
		string s; cin >> s;
		if(s=="#")break;
		int h=1,w=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='/')h++;
		}
		for(int i=0;i<s.size();i++){
			if(s[i]=='/')break;
			if(s[i]=='b')w++;
			else w+=s[i]-'0';
		}
		vector<vector<char>> fi(h,vector<char>(w,'.'));
		int y=0,x=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='/')y++,x=0;
			else if(s[i]=='b'){
				fi[y][x]='#';
				x++;
			}
			else{
				x+=s[i]-'0';
			}
		}
		int a,b,c,d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		fi[a][b]='.';
		fi[c][d]='#';
		for(int i=0;i<h;i++){
			char num='0';
			for(int j=0;j<w;j++){
				if(fi[i][j]=='#'){
					if(num!='0')printf("%c",num );
					printf("b");
					num='0';
				}
				else num++;
			}
			if(num!='0')printf("%c",num );
			if(i+1!=h)printf("/");
		}
		printf("\n");
	}
}

