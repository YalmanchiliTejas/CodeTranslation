#include<bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define uniq(x) (x).erase(unique(ALL(x)),(x).end())
#define SORT(x) sort(ALL(x))
#define REV(x) reverse(ALL(x))
#define foreach(it,x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define debug(x) cerr<<#x<<"="<<(x)<<endl
#define gett() cerr<<"Time:"<<clock()<<"ms."<<endl
#define ri(x) scanf("%d",&x);
#define rl(x) scanf("%lld",&x);
#define rlcfpoj(x) scanf("%I64d",&x);
#define pi(x) printf("%d",x);
#define pl(x) printf("%lld",x);
#define plcfpoj(x) printf("%I64d",x);
#define lfd() printf("\n");
#define sp() printf(" ");
string s;
int n;
bool wolf[100100];
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>s;
	s+=s[0];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			wolf[1]=i;
			wolf[2]=j;
			for(int k=2;k<=n+1;k++){
				wolf[k+1]=(1-((s[k-1]=='o')^(wolf[k]))^wolf[k-1]);
			}
			if(wolf[n+2]!=wolf[2])
				continue;
			if(wolf[n+1]!=wolf[1])
				continue;
			for(int i=1;i<=n;i++){
				if(wolf[i])
					cout<<"W";
				else
					cout<<"S";
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
