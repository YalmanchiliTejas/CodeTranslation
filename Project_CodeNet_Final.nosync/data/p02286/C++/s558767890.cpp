#include<cstdio>
#include<cassert>

//INSERT ABOVE HERE
template<typename T>
struct Treap{
  struct Node{
    Node *l,*r;
    T key,pri;
    Node(){}
    Node(T key,T pri):key(key),pri(pri){l=r=nullptr;}
  };
  
  inline Node* create(){
    return new Node();
  }
  
  inline Node* create(T key,T pri){
    return new Node(key,pri);
  }
  
  Node* rotR(Node* t){
    Node* s=t->l;
    t->l=s->r;
    s->r=t;
    return s;
  }
  
  Node* rotL(Node* t){
    Node* s=t->r;
    t->r=s->l;
    s->l=t;
    return s;
  }
  
  Node* insert(Node* t,T key,T pri){
    if(t==nullptr) return create(key,pri);
    if(key==t->key) return t;
    if(key < t->key){
      t->l=insert(t->l,key,pri);
      if(t->pri < t->l->pri) t=rotR(t);
    }else{
      t->r=insert(t->r,key,pri);
      if(t->pri < t->r->pri) t=rotL(t);
    }
    return t;
  }

  Node* erase(Node* t,T key){
    if(t==nullptr) return t;
    if(key < t->key) t->l=erase(t->l,key);
    else if(key > t->key) t->r=erase(t->r,key);
    else return del(t,key);
    return t;
  }

  Node* del(Node* t,T key){
    if(t->l==nullptr&&t->r==nullptr) return nullptr;
    if(t->l==nullptr) t=rotL(t);
    else if(t->r==nullptr) t=rotR(t);
    else if(t->l->pri < t->r->pri) t=rotL(t);
    else t=rotR(t);
    return erase(t,key);
  }

  Node* find(Node* t,T key){
    if(t==nullptr) return t;
    if(key < t->key) return find(t->l,key);
    if(key > t->key) return find(t->r,key);
    return t;
  }

  void print1(Node* t){
    if(t==nullptr) return;
    print1(t->l);
    printf(" %d",t->key);
    print1(t->r);
  }
  
  void print2(Node* t){
    if(t==nullptr) return;
    printf(" %d",t->key);
    print2(t->l);
    print2(t->r);
  }  
};

char s[10];
int main(){
  int q;  
  scanf("%d",&q);
  Treap<int> G;
  Treap<int>::Node* r=nullptr;
  
  for(int i=0;i<q;i++){    
    scanf("%s",s);
    if(s[0]=='i'){
      int key,pri;
      scanf("%d %d",&key,&pri);
      r=G.insert(r,key,pri);
    }
    if(s[0]=='d'){
      int key;
      scanf("%d",&key);
      r=G.erase(r,key);
    }
    if(s[0]=='f'){
      int key;
      scanf("%d",&key);
      puts((G.find(r,key)!=nullptr?"yes":"no"));
    }
    if(s[0]=='p'){
      G.print1(r);
      puts("");
      G.print2(r);
      puts("");
    }
  }
  return 0;
}

