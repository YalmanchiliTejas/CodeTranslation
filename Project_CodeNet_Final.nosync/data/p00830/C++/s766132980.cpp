#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);

struct node{
    vector<node*> children;
    node *parent;
    string name;
	bool directory;
    node(string name,node *parent,bool directory):name(name),parent(parent),directory(directory){}
	node *add(string new_name, bool directory){
        REP(i,children.size()){
            if(children[i]->name==new_name){
                return children[i];
            }
        }
        node *new_node=new node(new_name,this,directory);
        children.push_back(new_node);
        return new_node;
    }
    node *get(string s,int pos){
        assert(s[pos]=='/');
        pos++;
 
        string cur_name;
        while(s[pos]!='/'&&pos!=s.size()){
            cur_name+=s[pos];
            pos++;
        }

		node *n=NULL;
		if(cur_name==""){
			n=this;
		}else{
			if(cur_name=="."){
				n=this;
			}else if(cur_name==".."){
				n=parent;
			}else{
				REP(i,children.size()){
					if(children[i]->name==cur_name){
						n=children[i];
						break;
					}
				}
			}
			if(n==NULL){
				return NULL;
			}
		}
		if(pos==s.size()||(pos==s.size()-1&&s[pos]=='/')){
			if(n->directory||s[pos]=='/'){
				REP(i,n->children.size()){
					if(n->children[i]->name=="index.html"&&!n->children[i]->directory){
						return n->children[i];
					}
				}
				return NULL;
			}else{
	            return n;
			}
		}

		if(n->directory){
			return n->get(s,pos);
		}else{
			return NULL;
		}
    }
};
 
void construct(node *n,string &s,int pos){
    assert(s[pos]=='/');
    pos++;
    string name;
    while(s[pos]!='/'&&s[pos]!='\0'){
        name+=s[pos];
        pos++;
    }
    if(s[pos]=='\0'){
        n->add(name,false);
        return;
    }
    node *new_n=n->add(name,true);
    construct(new_n,s,pos);
}
 
int main()
{
    int n,m;
    while(cin>>n>>m,n|m){
        node *root=new node("/",NULL,true);
        REP(i,n){
            string s;
            cin>>s;
            construct(root,s,0);
        }
        REP(i,m){
            string s1,s2;
            cin>>s1>>s2;
            node *n1=root->get(s1,0);
            node *n2=root->get(s2,0);
            if(n1==NULL||n2==NULL){
                cout<<"not found"<<endl;
            }else if(n1==n2){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }
        }
    }
}