#include <iostream>
using namespace std;
typedef long long int lld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define MOD 1000000007
string s;
int d;
lld DP[1000000][100][2];
lld computeDP(int a, int b,int c){
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(DP[a][b][c]!=-1)return DP[a][b][c];
	DP[a][b][c]=0;
	if(c==1){
		int D=s[a]-'0';
		rep(digit,0,D+1){
			
			if(digit==D){
				DP[a][b][c]+=computeDP(a+1,(b+digit)%d,1);
			}else{
				DP[a][b][c]+=computeDP(a+1,(b+digit)%d,0);
			}
		}
		DP[a][b][c]%=MOD;
		return DP[a][b][c];
	}
	rep(digit,0,10){
		
		DP[a][b][c]+=computeDP(a+1,(b+digit)%d,0);
	}
	DP[a][b][c]%=MOD;
	return DP[a][b][c];
}
int main(){
	// your code goes here
	cin>>s;
	cin>>d;
	
	rep(i,0,s.size()+1){
		rep(j,0,d){
			DP[i][j][0]=-1;
			DP[i][j][1]=-1;
		}
	}
	rep(j,0,d){
		DP[s.size()][j][0]=0;
		DP[s.size()][j][1]=0;
	}
	DP[s.size()][0][0]=1;
	DP[s.size()][0][1]=1;
	lld ans=computeDP(0,0,1);
	/*rep(i,0,s.size()+1){
		rep(j,0,d){
			cout<<DP[i][j][0]<<";"<<DP[i][j][1]<<" ";
		}cout<<endl;
	}*/
	cout<<(ans+MOD-1)%MOD<<endl;
	return 0;
}