#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int N;
	int line[4][100001]={};
	char s[100001];
	cin>>N;
	cin>>s;
	line[0][0]=1;
	line[0][1]=1;
	line[1][0]=2;
	line[1][1]=2;
	line[2][0]=1;
	line[2][1]=2;
	line[3][0]=2;
	line[3][1]=1;
	bool flag[4]={};
	bool flag2[4]={};
	for(int i=0;i<4;i++){
		//printf("flag[%d]=%d\n",i,flag[i]);
	}
	for(int i=0;i<4;i++){
		for(int j=1;j<N-1;j++){
			if(line[i][j]==1 && line[i][j-1]==1){
				if(s[j]=='o')
					line[i][j+1]=1;
				else
					line[i][j+1]=2;
			}
			if(line[i][j]==1 && line[i][j-1]==2){
				if(s[j]=='o')
					line[i][j+1]=2;
				else
					line[i][j+1]=1;
			}
			if(line[i][j]==2 && line[i][j-1]==1){
				if(s[j]=='o')
					line[i][j+1]=2;
				else
					line[i][j+1]=1;
			}
			if(line[i][j]==2 && line[i][j-1]==2){
				if(s[j]=='o')
					line[i][j+1]=1;
				else
					line[i][j+1]=2;
			}
		}

		if(line[i][N-1]==1 && line[i][N-2]==1){
			if(s[N-1]=='o'){
				if(line[i][0]==1)
					flag[i]=1;
			}
			else{
				if(line[i][0]==2)
					flag[i]=1;
			}
		}
		if(line[i][N-1]==1 && line[i][N-2]==2){
			if(s[N-1]=='o'){
				if(line[i][0]==2)
					flag[i]=1;
			}
			else{
				if(line[i][0]==1)
					flag[i]=1;
			}
		}
		if(line[i][N-1]==2 && line[i][N-2]==1){
			if(s[N-1]=='o'){
				if(line[i][0]==2)
					flag[i]=1;
			}
			else{
				if(line[i][0]==1)
					flag[i]=1;
			}
		}
		if(line[i][N-1]==2 && line[i][N-2]==2){
			if(s[N-1]=='o'){
				if(line[i][0]==1)
					flag[i]=1;
			}
			else{
				if(line[i][0]==2)
					flag[i]=1;
			}
		}

//
		if(line[i][0]==1 && line[i][1]==1){
			if(s[0]=='o'){
				if(line[i][N-1]==1)
					flag2[i]=1;
			}
			else{
				if(line[i][N-1]==2)
					flag2[i]=1;
			}
		}
		if(line[i][0]==1 && line[i][1]==2){
			if(s[0]=='o'){
				if(line[i][N-1]==2)
					flag2[i]=1;
			}
			else{
				if(line[i][N-1]==1)
					flag2[i]=1;
			}
		}
		if(line[i][0]==2 && line[i][1]==1){
			if(s[0]=='o'){
				if(line[i][N-1]==2)
					flag2[i]=1;
			}
			else{
				if(line[i][N-1]==1)
					flag2[i]=1;
			}
		}
		if(line[i][0]==2 && line[i][1]==2){
			if(s[0]=='o'){
				if(line[i][N-1]==1)
					flag2[i]=1;
			}
			else{
				if(line[i][N-1]==2)
					flag2[i]=1;
			}
		}
	}
	for(int i=0;i<4;i++){
		//printf("flag[%d]=%d\n",i,flag[i]);
	}
	for(int i=0;i<4;i++){
		if(flag[i]==1 && flag2[i]==1){
			for(int j=0;j<N;j++){
				if(line[i][j]==1)
					printf("S");
				else if(line[i][j]==2)
					printf("W");
				else
					printf("err");
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}