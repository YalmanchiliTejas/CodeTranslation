#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-14
int stringintoint(string s){
	int res=0;
	int X=1;
	for(int i=(int)s.length()-1;i>=0;i--){
		res+=(s[i]-'0')*X;
		X*=10;
	}
	return res;
}
int main()
{
	while(true){
		int M,N;
		scanf("%d%d",&M,&N);
		if(M==0&&N==0)break;
		vector<int>ans;
		for(int i=0;i<M;i++)ans.push_back(i);
		int x=0;
		for(int i=1;i<=N;i++){
			string S;
			cin >> S;
			if(i%15==0){
				if(S!="FizzBuzz"){
					ans.erase(ans.begin()+x);
					x--;
				}
				x++;
			}
			else if(i%3==0){
				if(S!="Fizz"){
					ans.erase(ans.begin()+x);
					x--;
				}
				x++;
			}
			else if(i%5==0){
				if(S!="Buzz"){
					ans.erase(ans.begin()+x);
					x--;
				}
				x++;
			}
			else{
				if(stringintoint(S)!=i){
					ans.erase(ans.begin()+x);
					x--;
				}
				x++;
			}
			if(x>=(int)ans.size()){
				x=0;
			}
		}
		
		printf("%d",ans[0]+1);
		for(int i=1;i<(int)ans.size();i++){
			printf(" %d",ans[i]+1);
		}
		printf("\n");
	}
	return 0;
}