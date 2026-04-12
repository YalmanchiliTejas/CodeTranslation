#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pb push_back
#define bi_s binary_search
#define lb lower_bound
#define ub upper_bound
using namespace std;

int h;
int w;
char a[103][103];
vi v;

int main(){
	cin >>h >>w;
  	int cnt=0;
  	rep(i,h){
      	bool flag=0;
    	rep(j,w){
        	cin >>a[cnt][j];
          	if(a[cnt][j]=='#') flag=1; 
        }
      if(flag) cnt++;
    }
  //cout <<cnt <<endl;	
  
  rep(i,w){
    bool flag=1;
  	rep(j,cnt){
    	if(a[j][i]=='#') flag=0;
    }
  	if(flag) v.pb(i);
  }
  v.pb(1000);
  
  	rep(i,cnt){
    	rep(j,w){
          if(!bi_s(v.begin(),v.end(),j))
        	cout<<a[i][j];
        }
      	cout <<"\n";
    }
	  	
  
  
  	return 0;

}