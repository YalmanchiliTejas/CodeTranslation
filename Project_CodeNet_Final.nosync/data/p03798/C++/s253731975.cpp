#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define substr(s,f,t) (s.substr(f-1,t-f+1))
#define ALL(a) (a).begin(),(a).end()
#define Yes(hoge) cout<<((hoge)?"Yes":"No")<<endl;
#define YES(hoge) cout<<((hoge)?"YES":"NO")<<endl;
using namespace std;
struct Grid{ll x,y,t;};
struct Edge{ll to,cost;};
struct Graph{vector<vector<Edge>>E;int V;
  const ll Inf = llINF;const int MAX_V=201010;vector<ll>d;
  Graph(int n):E(n){d.resize(MAX_V);E.resize(n);V=n;}
  void init(){for(int i=0;i<MAX_V;i++)d[i]=Inf;}
  void add_edge(ll from,ll to,ll cost){E[from].pb({to,cost});}
};
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  string s;cin>>s;
  vi hoge(n);
  //h,h
  hoge[0]=1;
  hoge[1]=1;
  bool ans=false;
  for(int i=1;i<n;i++){
    if(i==n-1){
      bool hog=false;
      if(s[i]=='o'){
	if(hoge[i]>0){
	  if(hoge[i-1]==hoge[0])hog=true;
	}else{
	  if(hoge[i-1]!=hoge[0])hog=true;
	}
      }else{
	if(hoge[i]>0){
	  if(hoge[i-1]!=hoge[0])hog=true;
	}else{
	  if(hoge[i-1]==hoge[0])hog=true;
	}
      }
      if(hog){
	if(s[0]=='o'){
	  if(hoge[0]>0){
	    if(hoge[n-1]==hoge[1])ans=true;
	  }else{
	    if(hoge[n-1]!=hoge[1])ans=true;
	  }
	}else{
	  if(hoge[0]>0){
	    if(hoge[n-1]!=hoge[1])ans=true;
	  }else{
	    if(hoge[n-1]==hoge[1])ans=true;
	  }
	}
      }
    }else{
      if(s[i]=='o'){
	if(hoge[i]>0){
	  if(hoge[i-1]>0){
	    hoge[i+1]=1;
	  }else{
	    hoge[i+1]=-1;
	  }
	}else{
	  if(hoge[i-1]>0){
	    hoge[i+1]=-1;
	  }else{
	    hoge[i+1]=1;
	  }
	}
      }else{
	if(hoge[i]>0){
	  if(hoge[i-1]>0){
	    hoge[i+1]=-1;
	  }else{
	    hoge[i+1]=1;
	  }
	}else{
	  if(hoge[i-1]>0){
	    hoge[i+1]=1;
	  }else{
	    hoge[i+1]=-1;
	  }
	}
      }
    } 
  }
  if(ans){
    for(int i=0;i<n;i++)
      if(hoge[i]>0)
	cout<<"S";
      else
	cout<<"W";
    cout<<endl;
    return 0;
  }




  //h,o
  hoge[0]=1;
  hoge[1]=-1;
  for(int i=1;i<n;i++){
    if(i==n-1){
      bool hog=false;
      if(s[i]=='o'){
	if(hoge[i]>0){
	  if(hoge[i-1]==hoge[0])hog=true;
	}else{
	  if(hoge[i-1]!=hoge[0])hog=true;
	}
      }else{
	if(hoge[i]>0){
	  if(hoge[i-1]!=hoge[0])hog=true;
	}else{
	  if(hoge[i-1]==hoge[0])hog=true;
	}
      }
      if(hog){
	if(s[0]=='o'){
	  if(hoge[0]>0){
	    if(hoge[n-1]==hoge[1])ans=true;
	  }else{
	    if(hoge[n-1]!=hoge[1])ans=true;
	  }
	}else{
	  if(hoge[0]>0){
	    if(hoge[n-1]!=hoge[1])ans=true;
	  }else{
	    if(hoge[n-1]==hoge[1])ans=true;
	  }
	}
      }
    }else{
      if(s[i]=='o'){
	if(hoge[i]>0){
	  if(hoge[i-1]>0){
	    hoge[i+1]=1;
	  }else{
	    hoge[i+1]=-1;
	  }
	}else{
	  if(hoge[i-1]>0){
	    hoge[i+1]=-1;
	  }else{
	    hoge[i+1]=1;
	  }
	}
      }else{
	if(hoge[i]>0){
	  if(hoge[i-1]>0){
	    hoge[i+1]=-1;
	  }else{
	    hoge[i+1]=1;
	  }
	}else{
	  if(hoge[i-1]>0){
	    hoge[i+1]=1;
	  }else{
	    hoge[i+1]=-1;
	  }
	}
      }
    } 
  }
  if(ans){
    for(int i=0;i<n;i++)
      if(hoge[i]>0)
	cout<<"S";
      else
	cout<<"W";
    cout<<endl;
    return 0;
  }





  //o,o
  hoge[0]=-1;
  hoge[1]=-1;
  for(int i=1;i<n;i++){
    if(i==n-1){
      bool hog=false;
      if(s[i]=='o'){
	if(hoge[i]>0){
	  if(hoge[i-1]==hoge[0])hog=true;
	}else{
	  if(hoge[i-1]!=hoge[0])hog=true;
	}
      }else{
	if(hoge[i]>0){
	  if(hoge[i-1]!=hoge[0])hog=true;
	}else{
	  if(hoge[i-1]==hoge[0])hog=true;
	}
      }
      if(hog){
	if(s[0]=='o'){
	  if(hoge[0]>0){
	    if(hoge[n-1]==hoge[1])ans=true;
	  }else{
	    if(hoge[n-1]!=hoge[1])ans=true;
	  }
	}else{
	  if(hoge[0]>0){
	    if(hoge[n-1]!=hoge[1])ans=true;
	  }else{
	    if(hoge[n-1]==hoge[1])ans=true;
	  }
	}
      }
    }else{
      if(s[i]=='o'){
	if(hoge[i]>0){
	  if(hoge[i-1]>0){
	    hoge[i+1]=1;
	  }else{
	    hoge[i+1]=-1;
	  }
	}else{
	  if(hoge[i-1]>0){
	    hoge[i+1]=-1;
	  }else{
	    hoge[i+1]=1;
	  }
	}
      }else{
	if(hoge[i]>0){
	  if(hoge[i-1]>0){
	    hoge[i+1]=-1;
	  }else{
	    hoge[i+1]=1;
	  }
	}else{
	  if(hoge[i-1]>0){
	    hoge[i+1]=1;
	  }else{
	    hoge[i+1]=-1;
	  }
	}
      }
    } 
  }
  if(ans){
    for(int i=0;i<n;i++)
      if(hoge[i]>0)
	cout<<"S";
      else
	cout<<"W";
    cout<<endl;
    return 0;
  }



  //o,h
  hoge[0]=-1;
  hoge[1]=1;
  for(int i=1;i<n;i++){
    if(i==n-1){
      bool hog=false;
      if(s[i]=='o'){
	if(hoge[i]>0){
	  if(hoge[i-1]==hoge[0])hog=true;
	}else{
	  if(hoge[i-1]!=hoge[0])hog=true;
	}
      }else{
	if(hoge[i]>0){
	  if(hoge[i-1]!=hoge[0])hog=true;
	}else{
	  if(hoge[i-1]==hoge[0])hog=true;
	}
      }
      if(hog){
	if(s[0]=='o'){
	  if(hoge[0]>0){
	    if(hoge[n-1]==hoge[1])ans=true;
	  }else{
	    if(hoge[n-1]!=hoge[1])ans=true;
	  }
	}else{
	  if(hoge[0]>0){
	    if(hoge[n-1]!=hoge[1])ans=true;
	  }else{
	    if(hoge[n-1]==hoge[1])ans=true;
	  }
	}
      }
    }else{
      if(s[i]=='o'){
	if(hoge[i]>0){
	  if(hoge[i-1]>0){
	    hoge[i+1]=1;
	  }else{
	    hoge[i+1]=-1;
	  }
	}else{
	  if(hoge[i-1]>0){
	    hoge[i+1]=-1;
	  }else{
	    hoge[i+1]=1;
	  }
	}
      }else{
	if(hoge[i]>0){
	  if(hoge[i-1]>0){
	    hoge[i+1]=-1;
	  }else{
	    hoge[i+1]=1;
	  }
	}else{
	  if(hoge[i-1]>0){
	    hoge[i+1]=1;
	  }else{
	    hoge[i+1]=-1;
	  }
	}
      }
    } 
  }
  if(ans){
    for(int i=0;i<n;i++)
      if(hoge[i]>0)
	cout<<"S";
      else
	cout<<"W";
    cout<<endl;
    return 0;
  }
  cout<<-1<<endl;
  return 0;
}
