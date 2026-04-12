#include <cstdio>
#include <algorithm>
int num[100005];
bool same[100005];
using namespace std;
pair<int,int>P[100005];
int main(){
	while(1){
	int n;
	scanf("%d",&n);
	if(!n) break;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n-1;i++){
		if(num[i]==num[i+1]){
			same[i]=true;
		}else{
            same[i]=false;
        }
	} 
	int ans=0,st=0,e=0;
	for(int i=0;i<n-1;i++){
		if(num[i]!=num[i+1]){
			P[st]=make_pair(num[i],e);
			e=i+1;
			st++;
		}
	}
		P[st]=make_pair(num[n-1],e);
	for(int i=0;i<st;i++){
		if(P[i+1].second%2==1){
			for(int j=i;j>=0 && P[j].first!=P[i+1].first;j--){
				P[j].first^=1;
			}
		}
	}
	for(int i=0;i<=st;i++){
		if(!P[i].first){
			if(i==st){
				ans+=(n-P[i].second);
			}else{
				ans+=(P[i+1].second-P[i].second);
			}
		}
	}
	printf("%d\n",ans);
	}
	return 0;
}
		