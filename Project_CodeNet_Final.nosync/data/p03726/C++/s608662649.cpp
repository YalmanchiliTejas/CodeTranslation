#include <bits/stdc++.h>
using namespace std;

set<int> adjl[100005];
vector<int> orig[100005];
int p[100005];
bool removed[100005];

void dfs(int node,int parent){
    for (int x : orig[node]){
        if (x==parent) continue;
        adjl[node].insert(x);
        p[x] = node;
        dfs(x,node);
    }
}


int main(){
int n;
scanf("%d",&n);
for (int x = 0; x<n-1; x++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--;b--;
    orig[a].push_back(b);
    orig[b].push_back(a);
}
if (n==2){
    printf("Second");
    return 0;
}
int root = -1;
for (int x = 0; x<n; x++){
    if (orig[x].size()>1){
        root = x;
    }
}
p[root] = -1;
dfs(root,-1);
queue<int> q;
for (int x = 0; x<n; x++){
    if (adjl[x].size()==0){
        if (p[x]!=-1 && adjl[p[x]].size()==1){
            if (p[x]!=root)
                q.push(x);
        }
    }
}
while (!q.empty()){
    int node = q.front();
    q.pop();
    removed[node] = true;
    removed[p[node]] = true;
    if (p[p[node]]!=-1){
        adjl[p[p[node]]].erase(p[node]);
        if (adjl[p[p[node]]].size()==0){
            if (p[p[p[node]]]!=-1 && adjl[p[p[p[node]]]].size()==1){
                if (p[p[p[node]]]!=root)
                    q.push(p[p[node]]);
            }
        }
        else if (adjl[p[p[node]]].size()==1){
            int consider = *(adjl[p[p[node]]].begin());
            if (adjl[consider].size()==0){
                if (p[p[node]]!=root)
                    q.push(consider);
            }
        }
    }

}

for (int x = 0; x<n; x++){
    if (removed[x]) continue;
    int num1 = 0;
    for (int y : adjl[x]){
        if (adjl[y].size()==0) num1++;
    }
    if (num1>1){
        printf("First");
        return 0;
    }
}
if (adjl[root].size()==0){
    printf("First");
}
else{
    printf("Second");
}
}
