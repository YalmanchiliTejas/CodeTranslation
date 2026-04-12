#include<iostream>
#include<fstream>
#include<vector>
#include<cstdio>

using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define fin cin
#define N 0
#define E 1
#define S 2
#define W 3
int score[255];

pair<int,int> trick(char led,int *val,char *suit,char dealer){
  bool flag=false;//if true trump

  rep(i,4){
    if ( led == suit[i]){flag=true;}
  }

  if (flag == false)led=dealer;

  int who=-1,ret=0;
  rep(i,4){
    if ( suit[i]==led && val[i]>ret)ret=val[i],who=i;
  }
  return make_pair( who,1);
}

void solve(vector<string> *data,char led){
  int ans[2]={0};
  int next=N;
  rep(i,13){
    char card[4];
    int val[4];
    rep(j,4){
      if ( isdigit(data[j][i][0] ))val[j]=data[j][i][0]-'0';
      else val[j]=score[data[j][i][0]];
      card[j]=data[j][i][1];
    }
    pair<int,int> ret=trick(led,val,card,card[next]);
    next=ret.first;
    ans[ret.first%2]+=ret.second;
  }

  if ( ans[0]>ans[1]){
    cout << "NS " << ans[0]-6<<endl;
  }else {
    cout << "EW " << ans[1]-6<<endl;
  }

}


main(){
  score['T']=10;
  score['J']=11;
  score['Q']=12;
  score['K']=13;
  score['A']=14;
  char a;
  while(cin>>a && a != '#'){
    vector<string> in[4];
    rep(i,4){
      rep(j,13){
        string t;
        cin>>t;
        in[i].push_back(t);
      }
    }
    solve(in,a);
  }

}