#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

struct Tree{
 struct Node{ int l=-1,r=-1,p=-1; int v; int w; };
 vector<Node> V;
 int R=-1;

 int& parentchild(int v){
  if(v==R) return R;
  if(V[V[v].p].l==v) return V[V[v].p].l;
  else return V[V[v].p].r;
 }
 void swapidx(int a,int b){
  swap(parentchild(a), parentchild(b));
  swap(V[a], V[b]);
  if (V[a].l != -1) V[V[a].l].p = a;
  if (V[a].r != -1) V[V[a].r].p = a;
  if (V[b].l != -1) V[V[b].l].p = b;
  if (V[b].r != -1) V[V[b].r].p = b;
 }
 void rotL(int v){
  int w=V[v].r;
  parentchild(v)=w; V[w].p=V[v].p;
  V[v].r=V[w].l; if(V[v].r!=-1) V[V[v].r].p=v;
  V[v].p=w; V[w].l=v;
 }
 void rotR(int v){
  int w=V[v].l;
  parentchild(v)=w; V[w].p=V[v].p;
  V[v].l=V[w].r; if(V[v].l!=-1) V[V[v].l].p=v;
  V[v].p=w; V[w].r=v;
 }

 void fix(int v){
  while(true){
   int p=V[v].p;
   if(p==-1) return;
   if(V[p].w>=V[v].w) return;
   if(V[p].l==v) rotR(p); else rotL(p);
  }
 }

 void insert(int v, int w){
  int p=-1; int* pp=&R;
  while(*pp!=-1){
   p=*pp;
   if(v<V[p].v) pp=&V[p].l;
   else if(v>V[p].v) pp=&V[p].r;
   else return;
  }
  *pp=V.size();
  V.push_back({-1,-1,p,v,w});
  fix(V.size()-1);
 }
 int find(int v){
  int p=R;
  while(p!=-1){
   if(v==V[p].v) return p;
   if(v<V[p].v) p=V[p].l; else p=V[p].r;
  }
  return -1;
 }
 void erase(int v){
  if(v==-1) return;
  while(true){
   if(V[v].l!=-1 && V[v].r!=-1){
    if(V[V[v].l].w<V[V[v].r].w) rotL(v);
    else rotR(v);
   }
   else if(V[v].l!=-1) rotR(v);
   else if(V[v].r!=-1) rotL(v);
   else break;
  }
  swapidx(v,V.size()-1);
  parentchild(V.size()-1)=-1;
  V.pop_back();
 }

 void printPreorder(int p=-2){
  if(p==-2) p=R;
  if(p==-1) return;
  printf(" %d",V[p].v);
  printPreorder(V[p].l);
  printPreorder(V[p].r);
 }
 void printInorder(int p=-2){
  if(p==-2) p=R;
  if(p==-1) return;
  printInorder(V[p].l);
  printf(" %d",V[p].v);
  printInorder(V[p].r);
 }
};

Tree T;
int Q;

int main() {
 scanf("%d",&Q);
 rep(i,Q){
  string c;
  { char buf[10]; scanf("%s",buf); c=buf; }
  if(c=="insert"){
   int v,w; scanf("%d%d",&v,&w);
   T.insert(v,w);
  }
  else if(c=="find"){
   int v; scanf("%d",&v);
   if(T.find(v)==-1) printf("no\n"); else printf("yes\n"); fflush(stdout);
  }
  else if(c=="delete"){
   int v; scanf("%d",&v);
   T.erase(T.find(v));
  }
  else if(c=="print"){
   T.printInorder(); printf("\n");
   T.printPreorder(); printf("\n"); fflush(stdout);
  }
 }
}


