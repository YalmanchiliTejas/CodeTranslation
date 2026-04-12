#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
  long long n;
  cin >> n;
  vector<long long> x(n),y(n);
  vector<pair<pair<long long,long long>,long long> > data;
  for(long long i = 0;i < n;i++){
    cin >> x[i] >> y[i];
    if(y[i]>x[i]){
      swap(x[i],y[i]);
    }
    data.push_back(make_pair(make_pair(y[i],x[i]),i));
  }
  sort(data.begin(),data.end());
  long long xmax=x[0],xmin=x[0],ymax=y[0],ymin=y[0];
  long long xmaxi=0,xmini=0,ymaxi=0,ymini=0;
  for(long long i = 1;i < n;i++){
    if(xmax<x[i]){
      xmax = x[i];
      xmaxi = i;
    }
    if(xmin>x[i]){
      xmin = x[i];
      xmini = i;
    }
    if(ymax<y[i]){
      ymax = y[i];
      ymaxi = i;
    }
    if(ymin>y[i]){
      ymin = y[i];
      ymini = i;
    }
  }
  long long ans = (xmax-xmin)*(ymax-ymin);
  long long now = ymax-ymin;
  long long ya=ymax,yi=ymin,ne;
  long long fx = xmax-ymin;
  long long yza=ymax,yzi=ymax;
  long long xi;
  for(long long i = 0;i < n-1;i++){
    xi = data[i+1].first.first;
    ne = data[i].first.second;
    if(ne > yza) yza = ne;
    if(ne < yzi) yzi = ne;
    if(xi < yzi){
      yi = xi;
    }
    else{
      yi = yzi;
    }
    if((yza-yi)*fx < ans) ans = (yza-yi)*fx;
  }
  cout << ans << endl;
}
