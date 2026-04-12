#include <map>
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

int p[100];
int t[100];
int v[100];

double rui[100];
double ruitmp[100];
double ans[100];

int main(){
  int n,m,l;
  scanf("%d%d%d", &n, &m, &l);

  REP(i,n) scanf("%d%d%d", p+i, t+i, v+i);
  REP(i,n) rui[i] = ans[i] = 0.0;

  vector<pair<double,pair<int,int> > > vv;
  map<double, int> cnt;

  REP(i,n) REP(j,m + 1){
    double tm = (double)l / v[i] + t[i] * j;
    vv.push_back(make_pair(tm, make_pair(i, j)));
    cnt[tm]++;
  }

  sort(vv.begin(), vv.end());
  vector<pair<int, double> > buff;

  REP(i,vv.size()){
    {
      int id = vv[i].second.first;
      int rest = vv[i].second.second;
      
      double rp = 1.0; // p^rest * (1-p)^(m-rest) * m C rest
      REP(j,rest){
	rp *= (p[id] / 100.0);
	rp *= (double)(m - j) / (rest - j);
      }
      REP(j,m-rest){
	rp *= 1 - (p[id] / 100.0);
      }

      ruitmp[id] += rp;

      buff.push_back(make_pair(id, rp));
      rui[id] += rp;
    }

    if(i == vv.size() - 1 || vv[i].first != vv[i+1].first){
      REP(ii, buff.size()){
	double rp = buff[ii].second;
	int id = buff[ii].first;
	double prob = 1.0;
	REP(j,n) if(id != j){
	  prob *= (1.0 - rui[j]);
	}
	ans[id] += prob * rp;	
      }
      buff.clear();
    }
  }

  REP(i,n) printf("%.6f\n", ans[i]);

  return 0;
}