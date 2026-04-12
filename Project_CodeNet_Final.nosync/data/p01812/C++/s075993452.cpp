#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

#define CH(N,A,B) (A<=N&&N<B)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define RREP(i,a,b) for(int i=(b-1);a<=i;i--)

using namespace std;

int N,M,K,D[20],v[105][105];
bool visit[(1<<16)];
int bits[105] = {};

int main() {
  cin>>N>>M>>K;
  REP(i,0,M){
    int d;
    cin>>d;
    D[i] = d-1;
    bits[D[i]] = (1<<i);
  }
  REP(i,0,N){
    REP(j,0,K){
      cin>>v[i][j];
    }
  }
  REP(i,0,(1<<16)) visit[i] = false;
  queue< pair<int, int> > stq;  //????????¨?±?????????¨??¶???, ????????????
  stq.push(make_pair((1<<M)-1, 0));
  visit[(1<<M)-1] = true;;
  while(!stq.empty()){
    int state = stq.front().first;
    int step = stq.front().second;
    stq.pop();

    REP(j,0,K){ /*??¶???state????????????K????????????????????¨?????????????????????*/
      int nextState = 0;
      /*
      int nextState = state;
      vector<int> fromv;
      vector<int> tov;
      */
      REP(i,0,M){
        if(state & (1<<(i/*D[i]*/))){
          //fromv.push_back(/*i*//*D[i]*/bits[D[i]]);
          ////REP(k,0,M) if(v[D[i]][j]-1 == D[k]) tov.push_back(k);
          //if(bits[v[D[i]][j]-1] != 0) tov.push_back(bits[v[D[i]][j]-1]);
          if(bits[v[D[i]][j]-1] != 0) nextState |= bits[v[D[i]][j]-1];
        }
      }
      /*
      //REP(i,0,fromv.size()) nextState &= ~(1<<fromv[i]); //from????????????????????????????????¨???
      REP(i,0,fromv.size()) nextState &= ~fromv[i];
      //REP(i,0,tov.size()) nextState |= (1<<tov[i]);  //to????????????????????????????????????
      REP(i,0,tov.size()) nextState |= tov[i];
      */
      if(nextState==0){
        cout<<step+1<<endl;
        return 0;
      }
      if(!visit[nextState]){
        stq.push(make_pair(nextState, step+1));
        visit[nextState] = true;
      }
    }
  }

  return 0;
}