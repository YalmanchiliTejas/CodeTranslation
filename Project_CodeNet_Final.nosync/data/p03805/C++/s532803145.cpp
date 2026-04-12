#include <stdio.h> 
#include <stdlib.h> 
#include <vector> 
#include <memory.h> 
using namespace std; 
const int N=100; 
int n,m,cnt; 
bool b[N]; 
vector <int> a[N]; 
  
void DFS(int u){ 
    b[u]=true; 
  
    bool ok=true; 
    for (int i=1;i<=n;i++) 
        if (b[i]==false) ok=false; 
    if (ok) cnt++; 
  
    for (int i=0;int v=a[u][i];i++) 
        if (b[v]==false) DFS(v); 
    b[u]=false; 
} 
  
int main(){ 
    scanf("%d%d",&n,&m); 
    int x,y; 
    for (int i=1;i<=m;i++){ 
        scanf("%d%d",&x,&y); 
        a[x].push_back(y); 
        a[y].push_back(x); 
    } 
  
    for (int i=1;i<=n;i++){ 
        a[i].push_back(0); 
        b[i]=false; 
    } 
  
    cnt=0; 
    DFS(1); 
  
    printf("%d",cnt); 
} 