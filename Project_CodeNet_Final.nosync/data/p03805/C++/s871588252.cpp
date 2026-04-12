#define rep(i,N) for(int i=0;i<(int)N;i++)
#include <bits/stdc++.h>
using namespace std;
int main()
{
  bool thru;
  int N,M,count=0,loop=1;
  cin>>N>>M;
  vector<int> a(M),b(M),A;
  rep(i,N){A.push_back(i+1);}//初期順列
  vector<vector<bool>> get(N,vector<bool>(N,false));//検索表と初期化。
  rep(i,M){cin>>a.at(i)>>b.at(i);}
  rep(i,M)
  {
    get.at(a.at(i)-1).at(b.at(i)-1)=true;
    get.at(b.at(i)-1).at(a.at(i)-1)=true;
  }//辺が繋がっているかどうかの表。
  rep(i,N-1){loop*=(i+1);}//一桁目は1で固定する為、(N-1)!通りで良い。
  rep(i,loop)
  {
    thru=true;
    rep(j,N-1)
    {
      if(!(get.at(A.at(j)-1).at(A.at(j+1)-1)))thru=false;
    }
    if(thru){count++;}//全ての頂点が繋がっていた時。
    next_permutation(A.begin()+1,A.end());//一桁目は1で固定し次の順列へ。
  }
  cout<<count<<endl;
}