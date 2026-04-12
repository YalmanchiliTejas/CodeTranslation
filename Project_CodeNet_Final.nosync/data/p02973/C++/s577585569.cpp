#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int bit[maxn],n,b[maxn];
int get(int idx){
    int sum=0;
    while(idx>0){
        sum+=(bit[idx]);
        idx-=(idx&(-idx));
    }
    return sum;
}
void update(int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
    return;
}
map<int,int> m;
vector<int> a;


int main(){
    scanf("%d",&n);
    a.push_back(-1);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        a.push_back(b[i]);
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int i=1;i<(int)a.size();i++){
        m[a[i]]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(get(m[b[i]]-1)==0){
            ans++;
            update(m[b[i]],1);
            continue;
        }
        int pos=0,val=0,c=get(m[b[i]]-1);
        for(int i=19;i>=0;i--){
            if(pos+(1<<i)<=n&&val+bit[pos+(1<<i)]<c){
                pos+=(1<<i);
                val+=bit[pos];
            }
        }
        pos++;
        update(pos,-1);
        update(m[b[i]],1);
    }
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/
