#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
const int N=3e3+5,MAX=3e7,MOD=1e9+7;
 
using namespace std;
 
int n;
int a[N];

ll memo[N][N][2];

ll solve(int l ,int r,int turn){

	 if(l>r)return 0;
     
     ll &ret = memo[l][r][turn];

     if(ret != -1e18)return ret;
     
     if(turn == 0){

     	 
     	 	ret = a[l]+solve(l+1,r,!turn);
     	
     	 	ret = max(ret,a[r]+solve(l,r-1,!turn));
     }
     else{

     	 ret = -a[l]+solve(l+1,r,!turn);

     	 ret = min(ret , -a[r]+solve(l,r-1,!turn));
     }

     return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //#ifndef ONLINE_JUDGE
      //freopen("test.txt","r",stdin);
    //#endif

      scanf("%d",&n);


      for(int i=0;i<n;i++)scanf("%d",&a[i]);

      for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<2;k++)memo[i][j][k]=-1e18;


      printf("%lld\n",solve(0,n-1,0));

      
   
     
}