#include <bits/stdc++.h>
#define change_read() freopen("C:\\Users\\ACM2018\\Desktop\\in.txt","r",stdin)
#define change_write() freopen("C:\\Users\\ACM2018\\Desktop\\out.txt","w",stdout)
#define creat_read() freopen("C:\\Users\\ACM2018\\Desktop\\in.txt","w",stdout)
using namespace std;
const int maxm = 2e5+10;
struct p{
    int ind;
    long long x;
}mat1[maxm],mat2[maxm];
bool cmp(p a,p b){
    return a.x<b.x;
}
struct e{
    int from,to;
    long long val;
}edge[maxm<<4];
bool cmp2(e a,e b){
    return a.val<b.val;
}
int pre[maxm];
int fin(int a){
    return a==pre[a]?a:(pre[a]=fin(pre[a]));
}
long long uni(int a,int b,long long val){
    int aa = fin(a);
    int bb = fin(b);
    if(aa==bb) return 0;
    pre[aa] = bb;
    return val;
}
int main(){
//    change_read();
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        pre[i] = i;
        scanf("%lld%lld",&mat1[i].x,&mat2[i].x);
        mat1[i].ind = mat2[i].ind = i;
    }

    sort(mat1+1,mat1+n+1,cmp);
    sort(mat2+1,mat2+n+1,cmp);
    if(n==2){
        cout<<min(abs(mat1[2].x-mat1[1].x),abs(mat2[2].x-mat2[1].x))<<endl;
        return 0;
    }
    int flag = 0;
    for(int i = 2;i<n;i++){
        edge[flag++] = e{mat1[i].ind,mat1[i-1].ind,abs(mat1[i].x-mat1[i-1].x)};
        edge[flag++] = e{mat1[i].ind,mat1[i+1].ind,abs(mat1[i].x-mat1[i+1].x)};
        edge[flag++] = e{mat2[i].ind,mat2[i-1].ind,abs(mat2[i].x-mat2[i-1].x)};
        edge[flag++] = e{mat2[i].ind,mat2[i+1].ind,abs(mat2[i].x-mat2[i+1].x)};
    }
    long long ans = 0;
    sort(edge,edge+flag,cmp2);
    for(int i = 0;i<flag;i++){
        ans=ans+uni(edge[i].from,edge[i].to,edge[i].val);
    }
    printf("%lld\n",ans);
    return 0;
}











