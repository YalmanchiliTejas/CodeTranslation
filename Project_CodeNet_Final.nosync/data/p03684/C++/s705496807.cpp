#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll par[1000000];

ll find(ll a);
void combine(int a,int b);
bool same(int a,int b);
main(){
    vector<pair<pair<ll,ll>,ll>> E;//グラフの情報を保持している
    ll n,a,b,c,ans=0;
    cin>>n;
    pair<pair<ll,ll>,ll>v[n];
    for(int i=0;i<n;i++){
        cin>>v[i].first.first>>v[i].first.second;
        v[i].second=i;
    }

    sort(v, v+n, [](pair<pair<int, int>,int>p, pair<pair<int,int>,int>q){
  return p.first.first < q.first.first;
});
    for(int i=1;i<n;i++){
        a=v[i-1].second;
        b=v[i].second;
        c=fmin(abs(v[i-1].first.first-v[i].first.first),abs(v[i-1].first.second-v[i].first.second));
        E.push_back({{a,b},c});
    }

    sort(v, v+n, [](pair<pair<int, int>,int>p, pair<pair<int,int>,int>q){
    return p.first.second < q.first.second;
    });
    for(int i=1;i<n;i++){
        a=v[i-1].second;
        b=v[i].second;
        c=fmin(abs(v[i-1].first.first-v[i].first.first),abs(v[i-1].first.second-v[i].first.second));
        E.push_back({{a,b},c});
    }

    sort(E.begin(),E.end(), [](pair<pair<int, int>,int>p, pair<pair<int,int>,int>q){
      return p.second < q.second;
    });

for(int i=0;i<n;i++){
  par[i]=i;
}

for(int i=0;i<E.size();i++){
if(!same(E[i].first.first,E[i].first.second)){
    combine(E[i].first.first,E[i].first.second);
    ans+=E[i].second;
}
}

cout<<ans<<endl;
}

int find(int a){
int k;
k=a;
while(par[a]!=a){
a=par[a];
}
par[k]=a;
return a;
}
 
void combine(int a,int b){
int a1,b1;
a1=find(a);
b1=find(b);
if(a1!=b1){
par[b1]=a1;
}
}

bool same(int a,int b){
  if(find(a)==find(b))return true;
  return false;
}
