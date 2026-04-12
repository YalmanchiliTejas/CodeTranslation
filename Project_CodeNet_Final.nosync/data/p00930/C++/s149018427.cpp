#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 3e5+9;
int n,Q,sum[N];
char S[N];
priority_queue<int, vector<int>, greater<int> > que;
int flag[N*4],a[N*4];
int x,al,ar,add;
void build(int root,int l,int r) {
    flag[root] = 0;
    if(l==r) {
        a[root] = sum[l];
    }else{
        int mid=(l+r)>>1;
        build(root*2,l,mid);
        build(root*2+1,mid+1,r);
        a[root]=min(a[root*2],a[root*2+1]);
    }
}
void pushdown(int t) {
    if(t<<1 >= N*4)return;
    flag[t<<1]+=flag[t];flag[t<<1|1]+=flag[t];
    a[t<<1]+=flag[t];a[t<<1|1]+=flag[t];
    flag[t]=0;
}
void update(int root,int l,int r) {
    if(flag[root]!=0)pushdown(root);
    if(al <= l && r <= ar ) {
        a[root]+=add;flag[root]+=add;
    }else{
        int mid=(l+r)>>1;
        if(al<=mid)   update(root<<1,l,mid);
        if(ar>=mid+1) update(root<<1|1,mid+1,r);
        a[root]=min(a[root*2],a[root*2+1]);
    }
}
int ask(int root,int l,int r) {
    if(flag[root])pushdown(root);
    if(al<=l&&r<=ar) return a[root];
    int mid=(l+r)>>1;
    int ans=1e9;
    if (al<=mid) ans = min(ans,ask(root<<1,l,mid));
    if (ar>mid) ans = min(ans,ask(root<<1|1,mid+1,r));
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>Q) {
        cin>>(S+1);
        while(!que.empty())que.pop();
        for(int i=1;i<=n;i++){
            if(S[i]=='(')sum[i]=sum[i-1]+1;
            else sum[i]=sum[i-1]-1;
            if(S[i]==')') que.push(i);
        }
        build(1,1,n);
        while(Q--){
            cin>>x;
            if(S[x] == '(' ) {
                que.push(x);
                S[x] = ')';al=x;ar=n;add=-2;
                update(1,1,n);
                while(!que.empty()){
                    x = que.top();que.pop();
                    if(S[x]==')') break;
                }
                S[x]='(';al=x;ar=n;add=2;
                update(1,1,n);
            }else{
                int l=1,r=x;
                S[x]='(';al=x;ar=n;add=2;
                update(1,1,n);
                while(l<r){
                    int mid=(l+r) >> 1;
                    al=mid;ar=x;
                    if(ask(1,1,n)>=2)r=mid;
                    else l=mid+1;
                }
                S[l] = ')';que.push(l);
                al=l;ar=n;add=-2;
                update(1,1,n);
                x=l;
            }
            cout<<x<<endl;
        }
    }
    return 0;
}