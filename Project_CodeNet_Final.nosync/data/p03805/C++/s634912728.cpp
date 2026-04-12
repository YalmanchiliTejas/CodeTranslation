#include <bits/stdc++.h>

using namespace std;

int main(){
    int v,e;
    scanf("%d%d",&v,&e);
    vector< set<int> > g(v+1);
    for(int i=0;i<e;i++){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        g[t1].insert(t2);
        g[t2].insert(t1);
    }
    int perm[10];
    for(int i=0;i<v-1;i++){
        perm[i]=i+2;
    }
    int cnt=0;
    do{
        cnt++;
        if(g[1].count(perm[0])==0){
            cnt--;
            continue;
        }
        for(int i=1;i<v-1;i++){
            if(g[perm[i-1]].count(perm[i])==0){
                cnt--;
                break;
            }
        }
    }while(next_permutation(perm,perm+v-1));
    printf("%d\n",cnt);
    return 0;
}
