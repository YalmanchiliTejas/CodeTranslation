#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200005;
struct Node {
    int w, sz, sw;
    Node *f, *ch[2];
    Node(int w=0, Node *f=0) : 
	w(w), f(f) { ch[0]=ch[1]=0;sw=0;sz=1; }
    bool rc() { if(f) return f->ch[1]==this; }
    void flip() { swap(ch[0], ch[1]); sw ^= 1; }
    void down() {
	if(sw) {
	    if(ch[0]) ch[0]->flip();
	    if(ch[1]) ch[1]->flip();
	    sw = 0; 
	}
    }
    void up() {
	sz = 1;
	if(ch[0]) sz += ch[0]->sz;
	if(ch[1]) sz += ch[1]->sz;
    }
} *s;
void lk(Node *x, Node *y, int c) {
    if(x) x->f = y;
    if(y) y->ch[c] = x;
}
void rot(Node *x) {
    Node *y = x->f; int c = x->rc();
    x->down(); y->down();
    lk(x, y->f, y->rc());
    lk(x->ch[c^1], y, c);
    lk(y, x, c^1);
    y->up(); x->up();
    if(!x->f) s = x;
}
void Splay(Node *x, Node *to=0) {
    while(x->f!=to) {
	Node *y = x->f;
	if(y->f!=to) x->rc()==y->rc() ? rot(y) : rot(x);
	rot(x);
    }
}
Node *build(int l, int r, Node *f=0) {
    if(l>r) return 0;
    int mid = (l+r)>>1;
    Node *x = new Node(mid, f);
    x->ch[0] = build(l, mid-1, x);
    x->ch[1] = build(mid+1, r, x);
    x->up(); return x;
}
Node *kth(int k, Node *to=0, Node *x=s) {
    int size = 1; x->down(); // warn
    if(x->ch[0]) size += x->ch[0]->sz;
    if(k==size) return Splay(x, to), x;
    if(k<size) return kth(k, to, x->ch[0]);
    return kth(k-size, to, x->ch[1]);
}
int a[maxn];
void print(Node *x=s) {
    if(!x) return;
    x->down();
    print(x->ch[0]);
    printf("%d ", a[x->w]);
    print(x->ch[1]);
}
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) 
	scanf("%d", a + i);
    s = build(0, N+1); 
    for(int i=1,l,r; i<=N; ++i) {
	l = 1, r = i;
	kth(l); kth(r+2, s);
	s->ch[1]->ch[0]->flip();
    }
    kth(1); kth(N+2, s);
    print(s->ch[1]->ch[0]); puts("");
    return 0;
}
