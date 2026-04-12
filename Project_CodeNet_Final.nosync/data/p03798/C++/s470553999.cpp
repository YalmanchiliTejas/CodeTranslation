#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const int qq = 1e5 + 10;
ll n, m;
char str[qq];
int vis[qq];
bool judge(){
//	for(int i = 1; i <= n; ++i)
//		printf("%d ", vis[i]);
//	printf("\n");
	for(int i = 2; i < n; ++i)
		if(vis[i] == 1){
			if(str[i] == 'o'){
				if(vis[i + 1] != vis[i - 1])	return false;
			}else{
				if(vis[i + 1] == vis[i - 1])	return false;
			}
		}else{
			if(str[i] == 'o'){
				if(vis[i + 1] == vis[i - 1])	return false;
			}else{
				if(vis[i + 1] != vis[i - 1])	return false;
			}
		}
	if(vis[1] == 1){
		if(str[1] == 'o'){
			if(vis[2] != vis[n])	return false;
		}else{
			if(vis[2] == vis[n])	return false;
		}
	}else{
		if(str[1] == 'o'){
			if(vis[2] == vis[n])	return false;
		}else{
			if(vis[2] != vis[n])	return false;
		}
	}
	if(vis[n] == 1){
		if(str[n] == 'o'){
			if(vis[n - 1] != vis[1])	return false;
		}else{
			if(vis[n - 1] == vis[1])	return false;
		}
	}else{
		if(str[n] == 'o'){
			if(vis[n - 1] == vis[1])	return false;
		}else{
			if(vis[n - 1] != vis[1])	return false;
		}
	}
	return true;
}

void print(){
	for(int i = 1; i <= n; ++i)
		if(vis[i] == 1)	printf("S");
		else	printf("W");
	puts("");
}

int main(){
	scanf("%lld", &n);
	scanf("%s", str + 1);
	int flag = false;
	vis[1] = 1;
	vis[2] = 1;
	for(int i = 2; i < n; ++i)
		if(vis[i] == 1){
			if(str[i] == 'o')	vis[i + 1] = vis[i - 1];
			else				vis[i + 1] = (vis[i - 1] == 1 ? 0 : 1);
		}else{
			if(str[i] == 'x')	vis[i + 1] = vis[i - 1];
			else				vis[i + 1] = (vis[i - 1] == 1 ? 0 : 1);
		}
	flag = judge();
	if(flag == true){
		print();
		return 0;
	}
	vis[1] = 0;
	vis[2] = 0;
	for(int i = 2; i < n; ++i)
		if(vis[i] == 1){
			if(str[i] == 'o')	vis[i + 1] = vis[i - 1];
			else				vis[i + 1] = (vis[i - 1] == 1 ? 0 : 1);
		}else{
			if(str[i] == 'x')	vis[i + 1] = vis[i - 1];
			else				vis[i + 1] = (vis[i - 1] == 1 ? 0 : 1);
		}
	flag = judge();
	if(flag == true){
		print();
		return 0;
	}
	vis[1] = 1;
	vis[2] = 0;
	for(int i = 2; i < n; ++i)
		if(vis[i] == 1){
			if(str[i] == 'o')	vis[i + 1] = vis[i - 1];
			else				vis[i + 1] = (vis[i - 1] == 1 ? 0 : 1);
		}else{
			if(str[i] == 'x')	vis[i + 1] = vis[i - 1];
			else				vis[i + 1] = (vis[i - 1] == 1 ? 0 : 1);
		}
	flag = judge();
	if(flag == true){
		print();
		return 0;
	}
	vis[1] = 0;
	vis[2] = 1;
	for(int i = 2; i < n; ++i)
		if(vis[i] == 1){
			if(str[i] == 'o')	vis[i + 1] = vis[i - 1];
			else				vis[i + 1] = (vis[i - 1] == 1 ? 0 : 1);
		}else{
			if(str[i] == 'x')	vis[i + 1] = vis[i - 1];
			else				vis[i + 1] = (vis[i - 1] == 1 ? 0 : 1);
		}
	flag = judge();
	if(flag == true){
		print();
		return 0;
	}
	printf("-1\n");
}