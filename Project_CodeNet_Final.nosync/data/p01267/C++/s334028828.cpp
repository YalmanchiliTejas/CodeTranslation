#include<bits/stdc++.h>

using namespace std;

int main(){
	
	while(1){
		
		int n,a,b,c,x;
		
		cin>>n>>a>>b>>c>>x;
		
		if(n==0) break;
		
		int y[n];
		
		for(int i=0;i<n;i++){
			cin >> y[i];
		}
		
		int ri=0;
		int f=-1;
		
		while(f<=10001&&ri<n){
			if(x==y[ri]){
				ri++;
			}
			f++;
			x=(a*x+b)%c;
		}
		if(f>10000) cout << "-1" << endl;
		else cout << f << endl;
	}
		
	return 0;
	
}
