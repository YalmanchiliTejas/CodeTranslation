#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
int n, Deg[101000], Q[101000], head, tail;
int chk[101000];
int main(){
    int i, a, b, j;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
        Deg[a]++,Deg[b]++;
    }
    for(i=1;i<=n;i++){
        int c = 0;
        for(j=0;j<E[i].size();j++){
            if(Deg[E[i][j]]==1)c++;
        }
        if(c>=2){
            printf("First\n");
            return 0;
        }
        if(Deg[i]==1)Q[++tail] = i;
    }
    while(head < tail){
        a = Q[++head];
        if(chk[a])continue;
        chk[a] = 1;
        int p = -1;
        for(i=0;i<E[a].size();i++){
            if(!chk[E[a][i]])p = E[a][i];
        }
        chk[p] = 1;
        if(p==-1){
            printf("First\n");
            return 0;
        }
        for(i=0;i<E[p].size();i++){
            Deg[E[p][i]]--;
            if(Deg[E[p][i]]==1){
                Q[++tail] = E[p][i];
            }
        }
    }
    printf("Second\n");
}