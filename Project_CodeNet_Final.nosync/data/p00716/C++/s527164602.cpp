#include<iostream>
#include<vector>
using namespace std;

struct datum{
  datum(){};
  datum(bool type,double rrr,int cost){
    t=type;
    r=rrr;
    c=cost;
  }
  bool t;
  double r;
  int c;
};


int m;
int years;
vector<datum> data;

void init(){
  data.clear();
}

int input(){
  cin>>m>>years;
  int tmp;
  cin>>tmp;
  for(int i=0;i<tmp;i++){
    bool t;double r;int c;
    cin>>t>>r>>c;
    data.push_back(datum(t,r,c));
  }
  return 1;
}



int cul(int m,int years,datum d){
  int res=m;
  int add=0;
  for(int i=0;i<years;i++){
    int a,b;
    if(d.t){
      a = res;
      b = res*d.r;
      res = a + b - d.c;
    }else{
      a = res;
      b = res * d.r;
      res = a - d.c;
      add += b;
    }
  }
  res+=add;
  return res;
}

int solve(){
  int res=-100;
  for(int i=0;i<data.size();i++){
    int tmp=cul(m,years,data[i]);
    res=max(res,tmp);
  }
  return res;
}

int main(){
  int c;
  cin>>c;
  for(int i=0;i<c;i++){
    init(),input();
    cout<<solve()<<endl;;
  }
}