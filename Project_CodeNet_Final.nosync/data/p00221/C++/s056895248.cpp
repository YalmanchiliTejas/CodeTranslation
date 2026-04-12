/*
 * src.cpp
 *
 *  Created on: 2016/08/04
 *      Author: joi
 */

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;

const int MAX_M=1e3,MAX_N=1e4;

int m,n;

char S[MAX_N][256];
char s[256];

bool flg[MAX_M];
vector<int> out;

bool numchk(){
	int len=strlen(s);
	REP(i,len){
		if (s[i]<'0' || s[i]>'9'){
			return false;
		}
	}
	return true;
}

int cnt(){
	int res=0;
	REP(i,m){
		if (flg[i]){
			res++;
		}
	}
	return res;
}

int main(){
	do{
		scanf("%d %d",&m,&n);
		if (m || n){
			memset(flg,1,sizeof(flg));
			REP(i,n){
				scanf("%s",S[i]);
			}
			int p=0;
			FOR(i,1,n+1){
				strcpy(s,S[i-1]);
				if (i%3==0 || i%5==0){
					if (i%15==0 && strcmp(s,"FizzBuzz")!=0){
						flg[p]=false;
					}
					if (i%3==0 && i%5!=0 && strcmp(s,"Fizz")!=0){
						flg[p]=false;
					}
					if (i%5==0 && i%3!=0 && strcmp(s,"Buzz")!=0){
						flg[p]=false;
					}
				}else{
					if (!numchk()){
						flg[p]=false;
					}
					int ans=atoi(s);
					if (i!=ans){
						flg[p]=false;
					}
				}
				p++;
				p%=m;
				while (!flg[p]){
					p++;
					p%=m;
				}
				if (cnt()==1){
					break;
				}
			}
			out.clear();
			REP(i,m){
				if (flg[i]){
					out.push_back(i+1);
				}
			}
			REP(i,(int)out.size()){
				if (i) printf(" ");
				printf("%d",out[i]);
			}
			printf("\n");
		}
	}while (n || m);
	return 0;
}