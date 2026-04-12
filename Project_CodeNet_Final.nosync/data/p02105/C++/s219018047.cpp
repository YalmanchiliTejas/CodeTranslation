#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int N;
ll tmin,tmax;
vector<P> G[5];

int main(){
  cin>>N>>tmin>>tmax;
  
  for(int i=0;i<N;i++){
    int type;
    ll x,y;
    cin>>type>>x>>y;
    type--;
    G[type].push_back( P(x,y) );
  }
  for(int i=0;i<5;i++)G[i].push_back( P(0,0) );
  
  for(int i=0;i<3;i++){
    int target=i;
    for(int j=i+1;j<5;j++){
      if( G[target].size() > G[j].size() ){
        target=j;
      }
    }
    if(i!=target){
      vector<P> tmp;
      tmp=G[i];
      G[i]=G[target];
      G[target]=tmp;
    }
  }

  ll Asize= G[0].size() * G[1].size()  * G[2].size();
  //  if(Asize>500000)return 0;
  ll Bsize= G[3].size() * G[4].size();
  
  vector<P> A ( Asize );
  vector<P> B ( Bsize );

  int cc;
  cc=0;
  for(int i=0;i<(int)G[0].size();i++){
    P X=G[0][i];
    for(int j=0;j<(int)G[1].size();j++){
      P Y=G[1][j];
      for(int k=0;k<(int)G[2].size();k++){
        P Z=G[2][k]; 
        A[cc++]=P( X.first+Y.first+Z.first , X.second+Y.second+Z.second );
      }
    }
  }
  cc=0;
  for(int i=0;i<(int)G[3].size();i++){
    P X=G[3][i];
    for(int j=0;j<(int)G[4].size();j++){
      P Y=G[4][j];
      B[cc++]=P( X.first+Y.first , X.second+Y.second );
    }
  }
  
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());

  int l=B.size() ,r= B.size();
  
  map<ll,int> count;
  set<ll> st;
  for(int i=0;i<(int)A.size();i++){
    ll x=A[i].first;
    ll y=A[i].second;
    
    while(l-1>=0 && x + B[l-1].first >= tmin ){
      ll key=B[l-1].second;
      st.insert(key);
      count[ key ]++;
      l--;
    }
    
    while(r>l && x + B[r-1].first > tmax ){
      ll key=B[r-1].second;
      count[ key ]--;
      if( count[ key ] == 0 )  st.erase( key );
      r--;
    }

    if( st.lower_bound(tmin-y) != st.upper_bound(tmax-y) ){
      cout<<"Yes"<<endl;
      return 0;
    }
  }

  cout<<"No"<<endl;
  return 0;
}
           