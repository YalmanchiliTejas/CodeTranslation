#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

#define LL long long

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define itr iterator
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;

template< typename T > inline void read(T &x) {
    bool f; char ch; f=0; x=0; ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-12;
const int maxn=(int) 20000+20;
const int maxm=(int) 1e6+20;
const int maxk=(int) 5e2+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

//const int Table_size=26;
//struct SAM
//{
//    struct Node
//    {
//        Node *next[Table_size];
//        Node *fail;
//        int l,c;
//        int idx;
//        void clear(int _l,int _c) {memset(this,0,sizeof(Node)); l=_l; c=_c;}
//    }POOL[maxn<<1], *last, *root, *cur;
//
//    inline void init()
//    {
//        root = last = cur = POOL ;
//        root->clear(0,0);
//        root->idx=-1;
//    }
//
//    void create(Node *p,Node *np,int c)
//    {
//        Node *q = p->next[c], *nq = ++cur ;
//        *nq = *q ;
//        nq->l = p->l + 1 ;
//        q->fail = nq ;
//        if( np != NULL ) np->fail = nq ;
//        for( ; p && p->next[c] == q ; p = p->fail ) p->next[c] = nq ;
//    }
//
//    void add(char ch,char st,int idx)
//    {
//        int c=ch-st;
//        Node *p = last , *np = last = ++cur ;
//        np->clear(p->l+1,c);
//        np->idx=idx;
//        for( ; p && p->next[c] == NULL ; p = p->fail ) p->next[c] = np ;
//        if( p == NULL ) np->fail = root ;
//        else if( p->l + 1 == p->next[c]->l )  np->fail = p->next[c];
//        else create(p,np,c);
//    }
//}sam;
//
//int n;
//char str[maxn];
//
//void work()
//{
//    int tc; read(tc);
//    while(tc--)
//    {
//        scanf("%s",str); n=strlen(str);
//
//        sam.init();
//        for(int j=0;j<2;j++)
//            for(int i=0;i<n;i++)
//                sam.add(str[i],'a',i);
//
//
//
//    }
//}

void work()
{
    char str[55];
    scanf("%s",str);

    for(int i=0;i<5;i++)
    {
        if(str[i]=='A' && str[i+1]=='C')
        {
            puts("Yes");
            return ;
        }
    }
    puts("No");

}


//--------------end--------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}
