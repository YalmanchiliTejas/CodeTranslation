#include<cstdio>
#include<algorithm>
using namespace std;

int x[222222], ord[222222], rnk[222222];

int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",x+i);
    for(int i=0;i<n;i++) ord[i] = i;
    sort(ord,ord+n,[&](int i,int j){
        return x[i] < x[j];
    });

    for(int i=0;i<n;i++) rnk[ord[i]] = i;
    for(int i=0;i<n;i++){
        if(rnk[i] < n/2) printf("%d\n", x[ord[n/2]]);
        else printf("%d\n", x[ord[n/2-1]]);
    }
}
