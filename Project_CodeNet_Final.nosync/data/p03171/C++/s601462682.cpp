#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 100000000000000

using namespace std;




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	
	while(cin>>n){
		lint soma = 0;
		vector<lint> num(n), pda(n+1), pd(n+1);
		for(int i=0;i<n;i++){
			cin>>num[i];
			soma += num[i];
		}
		lint ans;
		for(int i=0;i<n;i++){
			for(int j=0; (i+j)<n;j++){
				pd[j] = max(num[j] - pda[j+1], num[i+j] - pda[j]);
			}
			pda = pd;
		}
		
		cout<<pd[0]<<"\n";
		
	}

	return 0;	
}
