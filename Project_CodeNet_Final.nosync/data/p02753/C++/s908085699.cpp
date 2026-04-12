/* ***********************************************
Author        :taciturnity
Created Time  :2020/2/21 8:23:51
File Name     :TEST.cpp
************************************************ */

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i = x;i <= y;++i)
#define fori(i,x,y) for(int i = x;i >= y; -- i)
#define bug puts("--------------")
const int N = 2e5+10;
const double eps = 0.00000001;
const ll mod = 1e9 + 7 ;
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
	string s;
	cin >> s;
	bool r1 = 0,r2 = 0;
	rep(i,0,s.size()-1){
		if(s[i] == 'A') r1 = 1;
		else r2 = 1;
	}
	if(r1&&r2) puts("Yes");
	else puts("No");
}