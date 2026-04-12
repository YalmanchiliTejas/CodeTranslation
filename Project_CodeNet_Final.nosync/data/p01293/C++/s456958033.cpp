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

char h;

string s[4][13];

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	map<char,int> mp;
	for(int i=2;i<10;i++){
		mp[(char)(i+'0')]=i;
	}
	mp['T']=10;
	mp['J']=11;
	mp['Q']=12;
	mp['K']=13;
	mp['A']=14;
	while(cin >> h,h!='#'){
		int win[2]={};
		for(int i=0;i<4;i++){
			for(int j=0;j<13;j++){
				cin >> s[i][j];
			}
		}
		int fi=0;
		for(int i=0;i<13;i++){
			int wi=0,mx=0;
			bool f=0;
			char c=s[fi][i][1];
			for(int j=0;j<4;j++){
				int r=mp[s[j][i][0]];
				char ss=s[j][i][1];
				if(f){
					if(ss==h&&r>mx){
						mx=r;
						wi=j;
					}
				}
				else{
					if(ss==h){
						f=1;
						mx=r;
						wi=j;
					}
					else{
						if(ss==c&&r>mx){
							mx=r;
							wi=j;
						}
					}
				}
			}
			fi=wi;
			win[wi%2]++;
		}
		if(win[0]>win[1]){
			printf("NS %d\n",win[0]-6);
		}
		else{
			printf("EW %d\n",win[1]-6);
		}
	}
}

