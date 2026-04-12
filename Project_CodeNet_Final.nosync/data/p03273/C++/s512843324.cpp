#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
#include <vector>
#include <queue>
#include <functional>
#include <random>
#include <time.h>
#include <cmath>
#include <cstdio>
#include <complex>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
bool tate[110],yoko[110];
int main() {
  ll h,w;
  cin>>h>>w;
  char c[110][110];
  for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>c[i][j];
  for(int i=0;i<h;i++){
    bool f=1;
    for(int j=0;j<w;j++){
      if(c[i][j]=='#')f=0;
    }
    if(f)yoko[i]=1;
  }
  for(int i=0;i<w;i++){
    bool f=1;
    for(int j=0;j<h;j++){
      if(c[j][i]=='#')f=0;
    }
    if(f)tate[i]=1;
  }
  for(int i=0;i<h;i++){
    if(yoko[i])continue;
    for(int j=0;j<w;j++){
    if(tate[j])continue;
    cout<<c[i][j];
    }
    cout<<endl;
  }
	return 0;
}
