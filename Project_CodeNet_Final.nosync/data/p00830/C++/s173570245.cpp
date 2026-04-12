#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<cstdio>
#include<string>
using namespace std;
#define DIR 1
#define FILE 2
#define ARB 3
#define REP(i,b,e) for(int i=b;i<e;i++)
#define rep(i,n) REP(i,0,n)
class Tree{
public:
  int type;
  string myname;
  map<string,Tree* > M;
  Tree(){type=DIR;M.clear();myname="";}
};

void get_path(string a,vector<string>&b){
  rep(i,a.size())if (a[i]=='/')a[i]=' ';
  stringstream sin(a);
  while(sin>>a)b.push_back(a);
}

void get_query(string a,vector<pair<string,int> > & b){
  REP(i,1,a.size()){
    string t;
    while(i<a.size() && a[i] != '/')t+=a[i++];
    b.push_back(make_pair(t,DIR) );
  }
  if ( b.size() == 0)return;
  string t="index.html";
  if ( a[a.size()-1]=='/')b.push_back(make_pair(t,FILE) );
  else b[b.size()-1].second =ARB;
}

void make_tree(Tree *a,vector<string>&b,int &p){
  if (b.size()==p){return;}
  Tree *next=a->M[b[p]];
  if ( next == 0){
    next = new Tree;
    next->myname=b[p];
    a->M[b[p]]=next;
    next->type = p+1==b.size()?FILE:DIR;
    make_tree(next,b,++p);
  }else make_tree(next,b,++p);  
}

Tree* Find_Page(Tree *a,vector<pair<string,int> >&b,int &p,Tree *prev){
  Tree *ret=a;
  while(p < b.size()){
    if (b[p].first == "."){p++;continue;}
    else if ( b[p].first ==".."){p++;return prev;}
    //exceptional case "index.html"
    Tree *next = a->M[b[p].first];
    if ( next == 0 || (next->type&b[p].second )==0  )return NULL;
    ret = Find_Page(next,b,++p,a);
    if ( ret == NULL)return NULL;
  }

  if (ret->type == FILE)return ret;
  ret = ret->M["index.html"];
  if ( ret == 0 || ret->type !=FILE)return NULL;
  return ret;
}

void solve(string *q,Tree *root){
  Tree *data[2];
  rep(i,2){
    vector<pair<string,int> > a;
    int p=0;
    data[i]=NULL;
    get_query(q[i],a);
    data[i]=Find_Page(root,a,p,NULL);
    if (  data[i] == NULL){puts("not found");return;}
  }
  if (data[0] == data[1] )puts("yes");
  else puts("no");
}

main(){
  int n,q;
  while(cin>>n>>q &&n){
    Tree root;
    string t;
    vector<string> a;
    int p=0;
    rep(i,n)cin>>t,get_path(t,a),make_tree(&root,a,p=0),a.clear();
    rep(i,q){
      string in[2];
      cin>>in[0]>>in[1];
      solve(in,&root);
    }
  }
  return false;
}