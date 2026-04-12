#include <iostream>
#include <cstdio>                                               //scanf,printf
#include <algorithm>                                            //max,min
#include <string>                                               //string
#include <cstring>                                              //strlen,strcat
#include <cctype>                                               //isalpha,tolower
#include <cmath>                                                //sqrt,sin
#include <stack>                                                //top,push
#include <queue>                                                //front,push
#include <vector>                                               //push_back,sort
#include <set>                                                  //insert,begin
#include <map>                                                  //insert,find
#include <list>                                                 //push_front,begin
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>                                               //pow,powf
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define ll long long
#define PL pair<long long, long long>
#define P pair<int,int>
#define mk make_pair
#define en endl;
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define rep(i,n) for(int i=0; i<n; i++)
#define MAX 200005

int main(){
  int n,x[MAX];
  vector<int> v;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>x[i];
    v.push_back(x[i]);
  }
  
  sort(v.begin(), v.end());
  for(int i=0; i<n; i++){
    int a=x[i];
    if(a<v[n/2]){
      cout<<v[n/2]<<en
    }else if(a==v[n/2]){
      cout<<v[n/2-1]<<en
    }else{
      cout<<v[n/2-1]<<en
    }
  }
}