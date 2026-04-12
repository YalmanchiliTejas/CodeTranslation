#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef pair< ll , ll > P;
typedef pair< ll , P > PP;

#define MAX 200005
int N;
ll x[MAX],y[MAX];
vector<PP> t;

int main(){
  set< PP > st;
  
  cin>>N;
  t.resize(N+N);
  for(int i=0;i<N;i++){
    cin>>x[i]>>y[i];
    t[i]=PP(x[i],P(i,0));
    t[i+N]=PP(y[i],P(i,1));
    st.insert(t[i]);
    st.insert(t[i+N]);
  }
  
  
  sort(t.begin(),t.end());

  ll ans=(1LL<<60);
  
  unordered_map<ll,int> mp;
  int L=0, count=0;
  int size=t.size();
  for(int i=0;i<size;i++){
    
    while(L<size && count<N){
      mp[ t[L].second.first ]++;
      if(mp[ t[L].second.first ]==1){
        count++;
        st.erase(t[L]);
      }else{

      }

      L++;
    }

    if(count==N){
      //      cout<<i<<' '<<L<<' '<<st.size()<<endl;
      set< PP > :: iterator it;
      it=st.end();
      it--;
      ll maxm=it->first;
      ll mini=st.begin()->first;
      ll width= t[L-1].first - t[i].first;
      ans=min( ans, width*(maxm-mini) );

      //      cout<<'a'<<endl;
    }


    mp[ t[i].second.first ]--;
    if(     mp[ t[i].second.first ]==0)count--;
    
    st.insert(t[i]);
  }

  cout<<ans<<endl;
  return 0;
}
