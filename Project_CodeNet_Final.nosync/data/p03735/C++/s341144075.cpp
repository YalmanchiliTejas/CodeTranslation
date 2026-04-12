#include<bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;

signed main(){
  int N;
  vector<pair<int,int>> in;
  vector<pair<int,int>> hoge;

  map<int,int> cona, conb;
  set<int> a, b;

  int ans = inf;

  cin>>N;

  in.resize(N);
  hoge.resize(N);

  for(int i = 0; i < N; i++){
    cin>>in[i].first>>in[i].second;

    hoge[i] = in[i];

    if(hoge[i].first < hoge[i].second) {
      swap(hoge[i].first, hoge[i].second);


    }
    a.insert(hoge[i].first);
    b.insert(hoge[i].second);

    cona[hoge[i].first]++;
    conb[hoge[i].second]++;

    hoge[i].second *= -1;
  }

  sort(hoge.begin(), hoge.end());


  for(int i = 0; i < N; i++){

    hoge[i].second *= -1;

    //cout<<hoge[i].first<<" "<<hoge[i].second<<endl;
  }

  for(int i = 0; i <= N; i++){
    int bmin = *b.begin();
    int bmax = *(--b.end());
    int amin = *a.begin();
    int amax = *(--a.end());

    ans = min(ans, (bmax - bmin) * (amax - amin));

    //cout<<"i = "<<i<<" <> "<<endl;
    //cout<<"bmax = "<<bmax<<" bmin = "<<bmin<<endl;
    //cout<<"amax = "<<amax<<" amin = "<<amin<<endl;
    /*
    for(int y : a){
      cout<<y<<" ";
    }
    cout<<endl;

    for(int y : b){
      cout<<y<<" ";
    }
    cout<<endl;
    */

    if(i == N) break;

    cona[hoge[i].first]--;
    cona[hoge[i].second]++;


    conb[hoge[i].first]++;
    conb[hoge[i].second]--;

    a.insert(hoge[i].second);
    b.insert(hoge[i].first);

    if(cona[hoge[i].first] == 0){

      a.erase(hoge[i].first);
    }

    if(conb[hoge[i].second] == 0){

      b.erase(hoge[i].second);
    }



  }

  cout<<ans<<endl;

  return 0;
}
