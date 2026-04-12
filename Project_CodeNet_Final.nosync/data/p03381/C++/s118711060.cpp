#include<bits/stdc++.h>

using namespace std;

int n,x[300000];
pair<int,int> p[300000];
int sol[300000];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        p[i]={x,i};
    }
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        int x = p[i].second ;
        if(i>n/2)sol[x]=p[n/2].first;
        else sol[x]=p[n/2+1].first;

    }
    for(int i=1;i<=n;i++){
        printf("%d\n",sol[i]);
    }

}
