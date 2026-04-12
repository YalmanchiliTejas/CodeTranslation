#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define mp make_pair
#define endl "\n"
#define pii pair<int,int> 
#define ff first
#define ss second
#define mii map<int,int>
#define si set<int>
#define sti stack<int>
#define qi queue<int>
#define vi vector<int>
#define pq priority_queue<int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M=1e9+7;
const int N=1e2+5;
int dp[N][2];
string s;
int d;

void add(int &x,int y){
	x=(x+y);
	if(x>=M) x-=M;
}

void find(int x){
	if(x==s.size()){return;}
	int temp[N][2];
	int up=s[x]-'0';
	memset(temp,0,sizeof(temp));
	for(int i=0;i<=9;i++){
		if(i<up){
			for(int j=0;j<d;j++){
				add(temp[(j+i)%d][0],dp[j][0]+dp[j][1]);
			}
		}
		else if(i==up){
			for(int j=0;j<d;j++){
				add(temp[(i+j)%d][0],dp[j][0]);
				add(temp[(i+j)%d][1],dp[j][1]);
			}
		}
		else{
			for(int j=0;j<d;j++){
				add(temp[(i+j)%d][0],dp[j][0]);
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			dp[i][j]=temp[i][j];
		}
	}
	find(x+1);
}

int32_t main(){
    cin>>s;
    cin>>d;
    memset(dp,0,sizeof(dp));
    dp[0][1]=1;
    find(0);
    int ans=(dp[0][0]+dp[0][1]-1+M)%M;
    cout<<ans<<endl;
}

