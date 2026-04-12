#include<iostream>
#include<map>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cassert>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<string,ll> psl;

bool cmp(const pil &a,const pil &b){
  if (a.second != b.second)return a.second > b.second;
  return a.first < b.first;
}

bool isPossible(int n,vector<pil> &in,int m,vector<pil> &fav,int lim,int hyou,int num){
  if (in.size() + num <= lim)return true;
  int fromIn=lim-num;
  ll req=0;
  for(int i=0;i<num;i++){
    if (in[fromIn].second < fav[i].second)continue;
    req+=in[fromIn].second-fav[i].second;
    if (in[fromIn].first < fav[i].first)req++;
  }
  return req <= hyou;
}

int solve(int n,vector<pil> &in,int m,vector<pil> &fav,int lim,int hyou){
  int ret=0;
  int l=0,r=min(lim,(int)fav.size());
  while(l <= r){
    int mid = (l+r)/2;
    bool isok=isPossible(n,in,m,fav,lim,hyou,mid);
    if (isok)ret=mid,l=mid+1;
    else r=mid-1;
  }
  return ret;
}

main(){
  int n,m,k,l;
  while(cin>>n>>m>>k>>l){
    if (n == 0 && m == 0 && k == 0 && l == 0)break;
    vector<string> name(n);
    vector<psl> in(n);
    vector<pil> all,fav;
    map<string,int> M;
    set<int> S;
    for(int i=0;i<n;i++){
      cin>>in[i].first>>in[i].second;
      name[i]=in[i].first;
    }
    sort(name.begin(),name.end());
    for(int i=0;i<n;i++){
      M[name[i]]=i;
    }

    for(int i=0;i<m;i++){
      string tmp;
      cin>>tmp;
      S.insert(M[tmp]);
    }

    for(int i=0;i<n;i++){
      int id = M[in[i].first];
      if (S.find(id) == S.end())all.push_back(make_pair(id,in[i].second));
      else fav.push_back(make_pair(id,in[i].second));
    }
    sort(all.begin(),all.end(),cmp);
    sort(fav.begin(),fav.end(),cmp);
    int ans = solve(n,all,m,fav,k,l);
    cout << ans << endl;
    /*
   //check
    int tar=k-ans;
    int req=0;
    if (tar >= all.size()){
    }else {
      for(int i=0;i<ans;i++){
	if (all[tar].second < fav[i].second)continue;
	int tmp=all[tar].second-fav[i].second;
	req+=tmp;
	fav[i].second+=tmp;
	if (all[tar].first < fav[i].first)req++,fav[i].second++;
      }
    }

    //cout << req <<" " << l << endl;
    assert(req <= l);
    if (ans < fav.size()){
      fav[ans].second+=(l-req);
    }
    vector<pil> a;
    for(int i=0;i<all.size();i++)a.push_back(all[i]);
    for(int i=0;i<fav.size();i++)a.push_back(fav[i]);

    sort(a.begin(),a.end(),cmp);
    */
    /*
    for(int i=0;i<a.size();i++){
      if (i < k)cout <<"ok " ;
      else cout <<"ng ";
      if (S.find(a[i].first) != S.end())cout <<"*";
      else cout << " ";
      cout << name[a[i].first] <<" "<< a[i].first <<" "<< a[i].second << endl;
    }
    */
    /*
    int cnt=0;
    for(int i=0;i<k;i++){
      if (S.find(a[i].first) != S.end())cnt++;
    }
    //cout <<"compare answer " << ans <<" "<< cnt << endl;
    assert(ans == cnt);
    */
    /*
    for(int i=0;i<n;i++)cout << name[i] << endl;
    cout <<"Not favor" << endl;
    for(int i=0;i<all.size();i++){
      cout << name[all[i].first] <<" " <<all[i].first <<" " <<  all[i].second << endl;
    }
    cout <<"favor " << endl;
    for(int i=0;i<fav.size();i++){
      cout << name[fav[i].first] <<" " <<fav[i].first <<" " <<  fav[i].second << endl;
    }
    */
  }
  return false;
}