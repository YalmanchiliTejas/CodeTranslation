#include<cstdio>
#include<algorithm>
struct Element{
    int v;
    int id;
    bool operator < (const Element &other)const{
        return v<other.v;
    }
};
Element a[200005];
int ans[200005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        a[i].id = i;
        scanf("%d",&a[i].v);
    }
    std::sort(a+1,a+1+n);
    int pos = n/2+1;
    for(int i = 1; i <= n; i++){
        if(i<pos) ans[a[i].id] = a[pos].v;
        else ans[a[i].id] = a[pos-1].v;
    }
    for(int i = 1; i <= n; i++) printf("%d\n",ans[i]);
    return 0;
}
