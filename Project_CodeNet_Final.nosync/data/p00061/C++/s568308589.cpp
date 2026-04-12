#include <cstdio>
#include <map>
using namespace std;

int tab[31];
bool isex[31];
map<int,int> m;
int main(){
    int a,b;
    for(;;){
        scanf("%d,%d",&a,&b);
        if(a==0&&b==0) break;
        m[a]=b;
        isex[b]=true;
    }
    int rank=1;
    for(int i=30;i>=0;i--){
        if(isex[i]){
            tab[i]=rank;
            rank++;
        }
    }
    int c;
    while(scanf("%d",&c)!=-1){
        printf("%d\n",tab[m[c]]);
    }
}