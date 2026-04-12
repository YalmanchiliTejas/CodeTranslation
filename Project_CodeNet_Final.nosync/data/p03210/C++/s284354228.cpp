#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<queue>
#include<map>
#define maxn 10005
#define mod 1000000007
#define INF 0x3f3f3f3f
#define PI 3.1415926
using namespace std;
typedef long long ll;

int main(){
    //freopen("Test.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	if(n == 3 || n == 5 || n == 7){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
    return 0;
}