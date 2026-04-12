#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cassert>
#include<sstream>
#include<map>
#include<set>
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define inf (1<<29)

using namespace std;

struct Tree
{
  string name;
  int index;
  bool hasPrev;
  Tree *prev;
  vector<Tree*> next;

  Tree(string name="^w^",bool hasPrev=false):name(name),hasPrev(hasPrev)
  {
    next.clear();
  }
};

int N,M,index;

const string html = "index.html";

void tree_walk(Tree *t)
{
  cout << "[" << t->index << ":" << t->name << " ";
  rep(i,t->next.size())tree_walk(t->next[i]);
  cout << " ]";
}

void ddfs(Tree *t)
{
  rep(i,t->next.size())
    {
      ddfs(t->next[i]);
      delete t->next[i];
    }
}

void init(Tree *tree)
{
  index = 0;
  tree->hasPrev = false;
  tree->name = "/";
  tree->index = 0;
}

void add(Tree *t,vector<string> &vec,int &pos)
{
  if(pos >= vec.size())return;

  if(vec[pos] == ".")
    {
      add(t,vec,++pos);
      return;
    }
  if(vec[pos] == "..")
    {
      if(t->hasPrev)add(t->prev,vec,++pos);
      else          add(t,vec,++pos);
      return;
    }

  rep(i,t->next.size())if(t->next[i]->name == vec[pos])
    {
      add(t->next[i],vec,++pos);
      return;
    }

  Tree *node = new Tree;
  node->name = vec[pos];
  node->hasPrev = true;
  node->prev = t;
  node->index = ++index;

  int idx = t->next.size(); 
  t->next.push_back(node);

  add(t->next[idx],vec,++pos);
}

vector<string> toVec(string line)
{
  rep(i,line.size())if(line[i] == '/')line[i] = ' ';
  stringstream ss(line);
  vector<string> vec;
  while(!(ss >> line).fail())vec.push_back(line);
  return vec;
}

void addTree(string line,Tree *tree)
{
  vector<string> vec = toVec(line);
  int pos = 0;
  add(tree,vec,pos);
}

void search(Tree *t,vector<string> &vec,int &pos,int &ans)
{
  /*
  if(vec.empty())
    {
      rep(i,t->next.size())if(t->next[i]->next.empty() && t->next[i]->name == html)
	{
	  cout << "vec.size() = " << vec.size() << endl;
	  ans = t->next[i]->index;
	  break;
	}
      return;
    }
  */

  //if(vec.size() != 1 && pos < vec.size() && vec[pos] == "/")return;
  //cout << "pos = " << pos << " vec : " << vec.size() << " " << (pos < vec.size()?vec[pos]:"END") <<endl;
  if(vec.size() <= pos)
    {
      pos--;
      if(vec[pos] != "/" && vec[pos] == t->name && t->next.empty())
	{
	  ans = t->index;
	}
      else
	{
	  rep(i,t->next.size())if(t->next[i]->next.empty() && t->next[i]->name == html)
	    {
	      ans = t->next[i]->index;
	      break;
	    }
	}
      return;
    }


  if(vec[pos] == ".")
    {
      search(t,vec,++pos,ans);
      return;
    }
  if(vec[pos] == "..")
    {
      if(t->hasPrev)search(t->prev,vec,++pos,ans);
      //else          search(t,vec,++pos,ans);
    
      return;
    }
  if(vec[pos] == "/")
    {
      search(t,vec,++pos,ans);
      return;
    }
 
  rep(i,t->next.size())if(t->next[i]->name == vec[pos])
    {
      search(t->next[i],vec,++pos,ans);
      return;
    }  


}

void compute(string query1,string query2,Tree *tree)
{
  int pos1,pos2,pos;
  pos1 = pos2 = inf;
  pos = 0;
  vector<string> vec = toVec(query1);
  if(query1[query1.size()-1] == '/')vec.push_back("/");
  //rep(i,vec.size())cout << "vec[" << i << "] = " << vec[i] << endl;
  rep(i,vec.size()-1)if(vec[i].find(".html") != string::npos)
    {
      if(vec[i+1] == "." || vec[i+1] == "..")
	{
	  cout << "not found" << endl;
	  return;
	}
    }
  search(tree,vec,pos,pos1);
  //cout << "sarch ---------------- fin1" << endl;

  vec = toVec(query2);
  pos = 0;
  if(query2[query2.size()-1] == '/')vec.push_back("/");
  //rep(i,vec.size())cout << "vec[" << i << "] = " << vec[i] << endl;
  rep(i,vec.size()-1)if(vec[i].find("index.html") != string::npos)
    {
      if(vec[i+1] == "." || vec[i+1] == "..")
	{
	  cout << "not found" << endl;
	  return;
	}
    }
  search(tree,vec,pos,pos2);
  //cout << "sarch ---------------- fin2" << endl;
  //cout << "pos1,pos2 = (" << pos1 << "," << pos2 << ")\n"; 
  if(pos1 == inf || pos2 == inf)cout << "not found" << endl;
  else if(pos1 == pos2)         cout << "yes" << endl;
  else                          cout << "no" << endl;

}

int main()
{
  while(cin >> N >> M,N|M)
    {  
      Tree tree;

      init(&tree);

      string line;
      rep(i,N)
	{
	  cin >> line,addTree(line,&tree);
	  //tree_walk(&tree);
	  //cout << endl;
	}
      //tree_walk(&tree);cout << endl;
      string q1,q2;
      rep(i,M)
	{     
	  cin >> q1 >> q2;
	  compute(q1,q2,&tree);
	}
      ddfs(&tree);
    }
}