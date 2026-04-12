#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

/*1-6,2-5,3-4,4-3,5-2,6-1*/
/*
    5         n
  4-1-3     w-u-e
    2         s
    6         b
*/
int top,west,north;
//map<string,int> table;
static string n="North";
static string s="South";
static string e="East";
static string w="West";
static string u="Up";//top
static string b="Bottom";

string l="Left";
string r="Right";

/*reference:http://blog.livedoor.jp/kenyoi/archives/4185821.html*/
//a=top,up; b=west; c=north;
int foo(string t){
  int tmp;
  if(t.compare(n)==0){
    tmp=north;north=top;top=7-tmp;
  }
  else if(t.compare(s)==0){
    tmp=top;top=north;north=7-tmp;
  }
  else if(t.compare(e)==0){
    tmp=top;top=west;west=7-tmp;
  }
  else if(t.compare(w)==0){
    tmp=west;west=top;top=7-tmp;
  }
  else if(t.compare(r)==0){
    tmp=north;north=west;west=7-tmp;
  }
  else if(t.compare(l)==0){
    tmp=west;west=north;north=7-tmp;
  }
  return top;
}

int main(void){
  int num;
  while(cin>>num){
    if(num==0) return 0;
    //a=top,up; b=west; c=north;
    top=1,west=4,north=5;
    int sum=1;
    for(int i=0;i<num;i++){
      string tmp;
      cin>>tmp;
      sum+=foo(tmp);
    }
    printf("%d\n",sum);
  }
}












/*
tanorthle.insert(make_pair(n,5));
table.insert(make_pair(s,2));
table.insert(make_pair(u,1));
table.insert(make_pair(b,6));

/*table.insert(make_pair(w,4));
table.insert(make_pair(e,3));

//use the easiest way
//just simulate it....

void bsun(){
  int tmp=table[n];
  table[n]=table[u];
  table[u]=table[s];
  table[s]=table[b];
  table[b]=tmp;
}
void wue(){
  int tmp=table[w];
  table[w]=table[b];
  table[b]=table[e];
  table[e]=table[u];
  table[u]=tmp;
}
void rotate(){
  //clockwise
  int tmp=table[w];
  table[w]=table[s];
  table[s]=table[e];
  table[e]=table[n];
  table[n]=tmp;
}

void test(){
  printf("  %d   \n",table[n]);
  printf("%d-%d-%d\n",table[w],table[u],table[e]);
  printf("  %d   \n  %d   \n",table[s],table[b]);
}

int main(int args, char *argc[]){


  int num;
  while(cin>>num){
    if(num==0) return 0;
    string tmp;
    int sum=1;

    table[n]=5;table[s]=2;
    table[u]=1;table[b]=6;

    table[w]=4;table[e]=3;

    for(int i=0;i<num;i++){
      cin>>tmp;
      if(tmp.compare(n)==0){
        bsun();
      }
      else if(tmp.compare(s)==0){
        bsun();
        bsun();
        bsun();
      }
      else if(tmp.compare(e)==0){
        wue();
      }
      else if(tmp.compare(w)==0){
        wue();
        wue();
      }
      else if(tmp.compare("Right")==0){
        rotate();
      }
      else{//case Left
        rotate();
        rotate();
        rotate();
      }
        sum+=table[u];
        test();printf("sum:%d\n\n",sum);

    }
    cout<<sum<<endl;
  }
  return 0;
}
*/
