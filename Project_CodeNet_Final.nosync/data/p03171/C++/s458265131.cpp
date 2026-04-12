#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0); cin.tie(0)
#define infl 1e18+9
#define sz(a) ((int)a.size())

const int nax=3005; 
ll maxx[nax][nax];  
ll minn[nax][nax];  
void solve(){
  int n;
  cin>>n; 
  vector<int> a(n); 
  for(int i=0;i<n;i++){
    cin>>a[i]; 
  }
  for(int l=1;l<=n;l++){
    for(int i=0;i+l-1<n;i++){
      int j=i+l-1; 
      if(l==1){
        maxx[i][j]=a[i]; 
        minn[i][j]=-a[i]; 
      }
      else {
        maxx[i][j]=max(minn[i][j-1]+a[j],minn[i+1][j]+a[i]); 
        minn[i][j]=min(maxx[i][j-1]-a[j],maxx[i+1][j]-a[i]); 
      }
    }
  }
  cout<<maxx[0][n-1]<<endl; 
}

int main()
{
	fast_io;
	clock_t beg=clock(); 
	solve(); 
	clock_t end=clock(); 
	fprintf(stderr,"%.2lf sec\n",(double)(end-beg)/CLOCKS_PER_SEC); 
	return 0;
}