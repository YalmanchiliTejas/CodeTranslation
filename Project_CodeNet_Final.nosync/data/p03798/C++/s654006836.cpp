#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする

struct edge{int to,cost;};
vector<int> G[100005];
 
ll n,i,j=1;
ll a,b;
bool flag = false;
long long int x[55];
int d,ans=0;
char s[100005];
bool k[100005];

int main(){
	cin>>n;
	cin>>s;
	//仮定１
	k[1]=k[2]=true;
	while(true){
		ans=0;
		for(i=3;i<=n;i++){
			if((s[i-2]=='o' && k[i-1]) || (s[i-2]=='x' && !k[i-1])){
				k[i]=k[i-2];
			}else{
				k[i]=!k[i-2];
			}
		}
		// for(i=1;i<=n;i++)cout<<k[i]<<endl;
		if((k[n] && k[1]==k[n-1] && s[n-1]=='o') || (k[n] && k[1]!=k[n-1] && s[n-1]=='x') || (!k[n] && k[1]==k[n-1] && s[n-1]=='x') || (!k[n] && k[1]!=k[n-1] && s[n-1]=='o')){
			ans ++;
		}
		if((k[1] && k[2]==k[n] && s[0]=='o') || (k[1] && k[2]!=k[n] && s[0]=='x') || (!k[1] && k[2]==k[n] && s[0]=='x') || (!k[1] && k[2]!=k[n] && s[0]=='o')){
			ans ++;
		}
		if(ans==2){
			for(i=1;i<=n;i++){
				if(k[i])cout<<"S";
				else cout<<"W";
			}
			break;
		}else{
			if(k[1]&&k[2]){
				k[1]=true;
				k[2]=false;
			}else if(k[1] && !k[2]){
				k[1]=false;
				k[2]=true;
			}else if(!k[1] && k[2]){
				k[1]=k[2]=false;
			}else{
				cout<<-1;
				break;
			}
		}
	}
	cout<<endl;
	return 0;
}