#include<cstdio>
#include<algorithm>
struct Point{
    int x,y;
    int id;
};
Point a[100005];
int indexX[100005],indexY[100005];
int posX[100005],posY[100005];
int used[100005];
//int x[100005], y[100005];
struct SegmentT{
    int l,r;
    int pl[2], pr[2];
    //bl[i] pair br[!i]
    int bl,br;
    SegmentT(){
        for(int i = 0; i < 2; i++){
            pl[i] = pr[i] = bl = br = -1;
        }
    }
};
SegmentT t[2][400005];

void preWork(int n){
    std::sort(a+1,a+1+n,[&](Point& u,Point& v){
        return u.x<v.x;
    });
    for(int i = 1; i <= n; i++){
        posX[a[i].id] = i;
        indexX[i] = a[i].id;
        //x[i] = a[i].x;
    }
    std::sort(a+1,a+1+n,[&](Point& u,Point& v){
        return u.y<v.y;
    });
    for(int i = 1; i <= n; i++){
        posY[a[i].id] = i;
        indexY[i] = a[i].id;
        //y[i] = a[i].y;
    }
    std::sort(a+1,a+1+n,[&](Point& u,Point& v){
        return u.id<v.id;
    });
}

int getValue(int u,int tag){
    if(!tag) return a[u].x;
    else return a[u].y;
}

int abs(int u){ return u>0?u:-u; }

int isBetter(int a,int b,int c,int d,int tag){
    if(a==-1 || b==-1) return 0;
    if(c==-1 || d==-1) return 1;
    return abs(getValue(a,tag)-getValue(b,tag))<abs(getValue(c,tag)-getValue(d,tag));
}

SegmentT merge(SegmentT& u,SegmentT& v,int tag){
    SegmentT res;
    res.l = u.l, res.r = v.r;
    for(int i = 0; i < 2; i++){
        if(u.pl[i]!=-1) res.pl[i] = u.pl[i];
        else res.pl[i] = v.pl[i];
        if(v.pr[i]!=-1) res.pr[i] = v.pr[i];
        else res.pr[i] = u.pr[i];
        if(isBetter(u.pr[i],v.pl[!i],res.bl,res.br,tag)) res.bl = u.pr[i], res.br = v.pl[!i];
    }
    if(isBetter(u.bl,u.br,res.bl,res.br,tag)) res.bl = u.bl, res.br = u.br;
    if(isBetter(v.bl,v.br,res.bl,res.br,tag)) res.bl = v.bl, res.br = v.br;
    return res;
}

void build(int p,int l,int r,SegmentT t[],int index[],int tag){
    t[p].l = l, t[p].r = r;
    if(l==r){
        t[p].pl[0] = t[p].pr[0] = index[l];
    }
    else{
        int m = (l+r)/2;
        build(2*p,l,m,t,index,tag);
        build(2*p+1,m+1,r,t,index,tag);
        t[p] = merge(t[2*p],t[2*p+1],tag);
    }
}

void change(int p,int x,SegmentT t[],int index[],int tag){
    if(t[p].l==t[p].r){
        t[p].pl[0] = t[p].pr[0] = -1;
        t[p].pl[1] = t[p].pr[1] = index[t[p].l];
    }
    else{
        int m = (t[p].l+t[p].r)/2;
        if(x<=m) change(2*p,x,t,index,tag);
        else change(2*p+1,x,t,index,tag);
        t[p] = merge(t[2*p],t[2*p+1],tag);
    }
}

void setUsed(int u,int n){
    used[u] = 1;
    int px = posX[u], py = posY[u];
    change(1,px,t[0],indexX,0);
    change(1,py,t[1],indexY,1);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){ 
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].id = i;
    }
    preWork(n);
    build(1,1,n,t[0],indexX,0);
    build(1,1,n,t[1],indexY,1);
    setUsed(1,n);
    long long answer = 0;
    for(int i = 2; i <= n; i++){
        //SegmentT res0 = t[0][1], res1 = t[1][1];
        int bl0 = t[0][1].bl, br0 = t[0][1].br;
        int bl1 = t[1][1].bl, br1 = t[1][1].br;
        int opt0 = abs(getValue(bl0,0)-getValue(br0,0)), opt1 = abs(getValue(bl1,1)-getValue(br1,1));
        if(opt0<opt1){
            answer += (long long)opt0;
            if(!used[bl0]) setUsed(bl0,n);
            else setUsed(br0,n);
        }
        else{
            answer += (long long)opt1;
            if(!used[bl1]) setUsed(bl1,n);
            else setUsed(br1,n);
        }
    }
    printf("%lld\n",answer);
    return 0;
}
