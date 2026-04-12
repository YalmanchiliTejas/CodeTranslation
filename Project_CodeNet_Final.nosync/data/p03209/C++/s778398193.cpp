#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
const int N=1e6+5,MAX=3e7,MOD=1e9+7;
 
using namespace std;

int n;
ll k;
ll whole[51],p[N];

ll solve(int indx,ll rem){

	if(indx==0){
		return rem>=1;
	}
	if(whole[indx]<=rem){
		return p[indx];
	}
	else{
		if((whole[indx-1]+2)<=rem){
			return p[indx-1]+1+solve(indx-1,rem-whole[indx-1]-2);
		}
		else{
			return solve(indx-1,rem-1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     cin>>n>>k;
     whole[0]=p[0]=1;
     for(int i=1;i<=n;i++){
     		whole[i]=whole[i-1]*2+3;
     		p[i]=p[i-1]*2+1;
     }

     cout<<solve(n,k)<<"\n";
     	
 }