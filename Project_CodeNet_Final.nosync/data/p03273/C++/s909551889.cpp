#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

char area[100][100];
using P=pair<char,bool>;

int main(){
  int h,w;
  std::cin >> h>>w;

  std::vector<std::vector<P> > area(h,std::vector<P>(w));

  std::vector<bool> iseh(h,true);
  std::vector<bool> isew(w,true);

  rep(i,h)rep(j,w){
    char temp;
    std::cin >> temp;
    area[i][j]=P(temp,1);
  }


  while (1) {
    int nh=h-1,bh=h-1;
    int nw=w-1,bw=w-1;


    rep(i,w){
        if(iseh[i]==false)continue;
        char start='a';
        bool flag=true;
        rep(j,h) {
          if(start!='a' && start!='.')flag=false;;
          if(area[j][i].second==false)continue;
          if(start=='a')start=area[j][i].first;
          else if(start!=area[j][i].first)flag=false;
        }

        if(flag && start=='.'){
          iseh[i]=false;
          rep(j,h)area[j][i].second=false;
          nh-=1;
        }


    }

    rep(i,h){
      if(isew[i]==false)continue;
      char start='a';
      bool flag=true;
      rep(j,w) {
        if(start!='a' && start!='.')flag=false;
        if(area[i][j].second==false){
          continue;
        }
        if(start=='a')start=area[i][j].first;
        else if(start!=area[i][j].first)flag=false;
      }

      if(flag && start=='.'){
        isew[i]=false;
        rep(j,h)area[i][j].second=false;
        nw-=1;
      }

    }



    if(nh==bh && nw==bw)break;

  }



      rep(i,h){
        if(isew[i]){
          rep(j,w){
            if(area[i][j].second==true)std::cout << area[i][j].first;
          }
          std::cout  << '\n';
        }
      }





  return 0;
}
