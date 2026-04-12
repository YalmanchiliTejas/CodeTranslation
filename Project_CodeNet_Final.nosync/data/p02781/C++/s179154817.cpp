#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,i,j,i1,i2,i3,k,ans,cur,zero=0,jud;
	string s;
	cin >> s >> k;
	n=s.size();
	vector<long long> p(n);
	
	for(i=0; i<n; i++){
		j=s[i]-'0';
		p[i]= j;
	}
	
	ans=0;
	
	if(k>n){
		cout << 0; return 0;
	}
	if(k==1){
		ans=p[0];
		ans+=9*(n-1);
		
	}else if(k==2){
		/*
		ans+=p[1];
		ans+=9*(n-2);
		ans+=(p[0]-1)*9*(n-1);
		ans+=81*(n-1)*(n-2)/2;
		*/
		jud=0;
		ans=81*n*(n-1)/2;
		ans-=9*(9-p[0])*(n-1);
		for(i=1; i<n && jud==0; i++){
			ans-=(9-p[i]);
			if(p[i]>0){
				jud++;
			}
		}
	}else{
		i1=-1; i2=-1;
		ans+=(p[0]-1)*81*(n-1)*(n-2)/2;
		for(i=1; i<n && i1==-1; i++){
			if(p[i]>0){
				i1=i;
			}
		}
		for(i=i1+1; i<n && i2==-1; i++){
			if(p[i]>0){
				i2=i;
			}
		}
		if(i2!=-1){
			ans+=p[i2];
			ans+=9*(n-i2-1);
		}
		if(i1!=-1){
			ans+=81*(n-i1-1)*(n-i1-2)/2;
		}
		ans+=729*(n-1)*(n-2)*(n-3)/6;
		ans+=(p[i1]-1)*9*(n-i1-1);
		/*
		ans+=p[2];
		ans+=9*(n-3);
		ans+=9*(p[1]-1)*(n-2);
		
		ans+=81*(p[0]-1)*(n-1)*(n-2)/2;
		
		ans+=729*(n-1)*(n-2)*(n-3)/6;
		
		jud=0;
		ans=729*n*(n-1)*(n-2)/6;
		ans-=81*(9-p[0])*(n-1)*(n-2)/2;
		for(i=1; i<n && jud==0; i++){
			ans-=9*(9-p[i])*(n-i-1);
			if(p[i]>0){
				jud++;
			}
		}
		*/
		
	}
	cout << ans;
	
	
}