// #include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#define pb emplace_back
#define LOCAL
  
using namespace std;
  
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+5;
typedef long long ll;
typedef pair<int,int> Pii;
 
template <typename T>inline void read(T& t){
    char c=getchar();t=0;
    int f=1;
    while(!isdigit(c)){
       if(c=='-')f=-1;
        c=getchar();
    }
    while(isdigit(c))t=t*10+c-48,c=getchar();
    t=f*t;
}
  
template <typename T,typename... Args> inline void read(T& t,Args&... args){
    read(t);read(args...);
}

char maze[1005][1005];
int vis[1005][1005];
int c1,c2,d1,d2;
queue<Pii> q[2];//q[0]代表第一种方式,q[2]代表第二种方式
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
 
int main(){
    int t=1;
    // read(t);
    while(t--){
        int n;
        read(n);
        puts(n>=30?"Yes":"No");
    }
    return 0;
}