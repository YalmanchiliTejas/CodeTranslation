#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)





int main() {
	ll H,W;
  	cin>>H>>W;
  	string A[H];
  	rep(i,H) cin>>A[i];
  	int count=0;
  	rep(i,H){
     	rep(j,W){
         	if(A[i][j]=='#') count++; 
        }
    }
  
  	if(count==H+W-1) cout<<"Possible"<<endl;
  	else cout<<"Impossible"<<endl;
  
}