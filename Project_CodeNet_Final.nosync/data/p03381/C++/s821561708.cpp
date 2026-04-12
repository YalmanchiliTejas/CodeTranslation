#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5+15;

int ar[N],temp[N];

int find(int x,int n){
    int l=1,r= n,mid;

    while(l<r){
        mid = (l+r+1)/2;
        if(x<temp[mid])
            r = mid-1;
        else
            l = mid;
    }
    return l;
}
int pen[N];
void update(int ind,int x){
    while(ind<N)
        pen[ind] += x, ind+= ind&(-ind);
}
int query(int ind){
    int ret=0;
    while(ind)
        ret += pen[ind],ind = ind&(ind-1);
    return ret;
}
int solve(int n){
    int m = (n+1)/2;
    int l= 1,r = N-1,mid;

    while(l<r){
        mid = (l+r)/2;

        if(m<=query(mid))
            r= mid;
        else
            l = mid+1;
    }

    return temp[l];
}
int main(){

    //freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d",&ar[i]);temp[i]= ar[i];
    }
    sort(temp+1,temp+n+1);
    for(int i=1;i<=n;++i){
        ar[i]= find(ar[i],n);
    }
    for(int i=1;i<=n;++i){
        update(ar[i],1);
    }
    for(int i=1;i<=n;++i){
        update(ar[i],-1);

        printf("%d\n",solve(n-1));

        update(ar[i],1);
    }
    return 0;
}