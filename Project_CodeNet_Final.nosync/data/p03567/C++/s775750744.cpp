#include<bits/stdc++.h>
using namespace std;
int n,len1,len2,fail[1000],bj,v,x,y;
char S[10000],U[1000];
int find(int i){
	while(U[i+1] != U[v]){
		if(i == -1) return -1;
		else i = fail[i];
	}
	return i+1;
}
int f(int i){
	while(U[i+1] != S[y]){
		if(i == -1) return -1;
		else i = fail[i];
	}
	return i+1;
}
int main(){
	scanf("%s",S);
	len1 = 2;
	len2 = strlen(S);
	U[0] = 'A';U[1] = 'C'; 
	fail[0] = -1;
	for(int i = 1; i < len1; ++i){
		v = i;
		fail[v] = find(fail[v-1]);
	}
	x = -1;
	y = -1;
	for(int i = 0; i < len2; ++i){
		y++;
		if(U[x+1] == S[y]) x++;
		else x = f(x);
		if(x == len1 - 1){
			printf("Yes");
			bj = 1;
			break;
		}
	}
	if(!bj) printf("No");
	return 0;
}