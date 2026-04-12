#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define sym cout<<"---------"<<endl;
#define ll long long
#define PL pair<long long, long long>
#define P pair<int,int>
#define mk make_pair
#define en endl
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define RE return 0
#define int ll

#define MAX 3000005

int dis[MAX];

signed main(){
  int n;
  cin>>n;
  for(int i=1; i<=n; i++){
    cin>>dis[i];
  }
  
  int maxl=1;
  bool clear_fir=true;
  for(int i=1; i<=n; i++){
    if(dis[i]>=10){
      int d=dis[i]/10;
      maxl=max(maxl,i+d);
    }else{
      if(maxl>i) continue;
      else clear_fir=false;
    }
  }
  
  int minl=n;
  bool clear_sec=true;
  for(int i=n; i>=1; i--){
    if(dis[i]>=10){
      int d=dis[i]/10;
      minl=min(minl,i-d);
    }else{
      if(minl<i) continue;
      else clear_sec=false;
    }
  }
  
  if(clear_sec&&clear_fir){
    cout<<"yes"<<en;
  }else{
    cout<<"no"<<en;
  }
}

