#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
long long num_size[51];
long long num_size_p[51];
vector<long long> p_sizeN(int N,long long start,long long x){
  if(start>x)return vector<long long>{0,0};
  if(N==0)return vector<long long>{1,1};//p,size
  if(num_size[N]!=-1){
    if(num_size[N]+start<x){
      return vector<long long>{num_size_p[N],num_size[N]};
    }
  }
  long long cur=start;
  long long num_p=0;
  long long size=0;
  cur+=1;size+=1;//B
  do{
  	if(cur>=x)break;
  	vector<long long> n_1_1=p_sizeN(N-1,cur,x);
  	num_p+=n_1_1[0];//P
  	size+=n_1_1[1];cur+=n_1_1[1];//size
  	if(cur>=x)break;
  	cur+=1;num_p+=1;size+=1;//P
  	if(cur>=x)break;
  	n_1_1=p_sizeN(N-1,cur,x);
  	num_p+=n_1_1[0];//P
  	size+=n_1_1[1];cur+=n_1_1[1];//size
  	if(cur>=x)break;
  	cur+=1;size+=1;//B
    num_size[N]=size;
    num_size_p[N]=num_p;
  }while(false);
  return vector<long long>{num_p,size};
};
int main(){
  for(int i=0;i<52;++i){num_size[i]=-1;num_size_p[i]=-1;}
  long long N,X;
  cin>>N>>X;
  cout<<p_sizeN(N,0,X)[0];
  return 0;
}