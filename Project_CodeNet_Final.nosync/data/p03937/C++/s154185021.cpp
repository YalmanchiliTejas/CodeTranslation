#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define ALL(x) (x).begin(),(x).end()
using namespace std;

inline lli getint(){
    lli n;
    scanf("%lld",&n);
    return n;
}

inline vector<lli> getints(int n){
    vector<lli> a(n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    return a;
}

inline string getstr(){
  string s;
  cin>>s;
  return s;
}

inline string slice(string s,int a,int b){
  return s.substr(a,b-a-1);
}
void dumpints(vector<lli> a){
  cout<<"[";
  for(int i=0;i<a.size()-1;i++){
    cout<<a[i]<<",";
  }
  cout<<a[a.size()-1]<<"]"<<endl;
}

template<class T> bool ifinclude(vector<T> a,T x){
    auto itr=find(a.begin(),a.end(),x);
    return distance(a.begin(),itr)!=a.size();
}

int main(void){
  int H=getint(),W=getint();
  vector<string> a(H);
  FOR(i,H){
    a[i]=getstr();
  }
  for(int i=1;i<H;i++){
    for(int j=0;j<W-1;j++){
      if(a[i][j]=='#'){
        for(int k=i-1;k>=0;k--){
          for(int l=j+1;l<W;l++){
            if(a[k][l]=='#'){
              cout<<"Impossible"<<endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout<<"Possible"<<endl;
  return 0;
}
