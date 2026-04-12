#include<iostream>
#include<cmath>
#include<vector>
#include<string>
typedef unsigned long long ull;
#define rep(i,a) for(int i=0;i<a;i++)
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const double eps = 1e-10;
const double pi = acos(-1);
const double inf = (int)1e8;

int main(void){
  int N,T,E;
  cin>>N>>T>>E;
  vector<int> in(N);
  rep(i,N)cin>>in[i];
  bool find = false;
  rep(i,N){
    int timer = 0;
    while(timer < T){
      timer+=in[i];
    }
    if(timer<=T+E){
      find = true;
      cout<<++i<<endl;
      break;
    }
  }						
  if(!find)cout<<-1<<endl;
}