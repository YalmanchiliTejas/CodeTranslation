#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
#define  MAXN    600010
using namespace std;
struct SegTree {
       int left, right, mid, val, add;
       SegTree () {}
} tree[MAXN<<1];
char str[MAXN];
int n, q, prefix[MAXN];
inline int LC(int x) { return x<<1; }
inline int RC(int x) { return x<<1|1; }
inline void push_down (int rt) {
     if (tree[rt].add == 0) 
        return;  
     tree[rt].val += tree[rt].add;
     if (tree[rt].left != tree[rt].right) {
        tree[LC(rt)].add += tree[rt].add;
        tree[RC(rt)].add += tree[rt].add;
     }
     tree[rt].add = 0;  
}
inline void push_up (int rt) {  
     tree[rt].val = min((tree[LC(rt)].val+tree[LC(rt)].add),
     (tree[RC(rt)].val+tree[RC(rt)].add))+tree[rt].add;
}
void makeTree (int L,int R,int rt) {
     tree[rt].left = L;
     tree[rt].right = R;
     tree[rt].mid = (L+R)>>1;
     tree[rt].add = 0;     
     if (L == R) {
        tree[rt].val = prefix[L+1];
        return ;
     } 
     int mid = tree[rt].mid;
     makeTree (L,mid,LC(rt));
     makeTree (mid+1,R,RC(rt));
     push_up (rt);    
}
void update (int L,int R,int rt,int x) {
     push_down (rt);
     if (L<= tree[rt].left && tree[rt].right<=R) {
        tree[rt].add += x;
        return ;
     }
     int mid = tree[rt].mid;
     if (R <= mid) 
        update (L,R,LC(rt),x);
     else if (L > mid)
        update (L,R,RC(rt),x);
     else {
        update (L,R,LC(rt),x);       
        update (L,R,RC(rt),x);  
     }
     push_up (rt);
}
int query (int L,int R,int rt) {
     push_down (rt);
     if (L<= tree[rt].left && tree[rt].right<=R) 
        return tree[rt].val;
     int mid = tree[rt].mid, tmp;
     if (R <= mid)
        tmp = query(L,R,LC(rt));
     else if (L > mid)
        tmp = query(L,R,RC(rt));
     else
        tmp = min( query(L,R,LC(rt)), query(L,R,RC(rt)) );
     return tmp;   
}
void fix (set<int> &prev,set<int> &next,char before,int x) {
     prev.erase(x);
     next.insert(x);
     int p, b = ( before == '(' ? -1 : 1 );
     str[x] = ( before == '(' ? ')': '(' );
     update (x,n-1,1,2*b);
     int l = 0, r = x;
     while (l < r) {
           int mid = (l+r)>>1;
           p = *next.lower_bound(mid);
           if (query(p,n-1,1) >= 2*b)
              r = mid;
           else
              l = mid+1;    
     }     
     p = *next.lower_bound(l);
     update (p,n-1,1,-2*b);
     next.erase (p);
     prev.insert (p);
     str[p] = before;
     printf ("%d\n",p+1);
}
int main(void) {
    while ( scanf("%d%d",&n,&q)==2 ) {
          scanf ("%s",str);
          int x;
          set <int> left, right;
          prefix[0] = 0;
          for (int i=0;i<n;++i)
              if (str[i] == '(') {
                 prefix[i+1] = prefix[i]+1;
                 left.insert (i);        
              }
              else {
                 prefix[i+1] = prefix[i]-1;
                 right.insert (i);  
              }  
          makeTree (0,n-1,1);              
          for (int i=0;i<q;++i) {
              scanf ("%d",&x);
              x--;
              if (str[x] == '(') 
                 fix(left,right,str[x],x);
              else if (str[x] == ')')
                 fix(right,left,str[x],x); 
          }
    }
    return 0;    
}