#include <bits/stdc++.h>
using namespace std;

int main(){
	int k,len,i,j;
	bool f=false;
	long long sum=0;
	string n;
	cin>>n>>k;
	len=n.size();
	switch(k){
		case 1:
			cout<<(len-1)*9+n[0]-'0';
			break;
		case 2:
			for(i=1;i<len;i++){
				sum+=9*9*(i-1);
			}
			sum+=(n[0]-'1')*9*(len-1);
			for(i=1;i<len;i++){
				if(n[i]!='0'){
					sum+=n[i]-'0';
					sum+=(len-i-1)*9;
					cout<<sum;
					f=true;
					break;
				}
			}
			if(f==false) cout<<sum;
			break;
		case 3:
			for(i=1;i<len;i++){
				sum+=729*(i-1)*(i-2)/2;
			}
			sum+=(n[0]-'1')*81*(len-1)*(len-2)/2;
			for(i=1;i<len;i++){
				if(n[i]!='0'){
					sum+=(n[i]-'1')*9*(len-i-1);
					for(j=i+1;j<len;j++){
						if(n[j]!='0'){
							sum+=n[j]-'0';
							sum+=(len-j-1)*9;
							break;
						}
					}
					sum+=(len-i-1)*81*(len-i-2)/2;
					cout<<sum;
					f=true;
					break;
				}
			}
			if(f==false) cout<<sum;
			break;
	}
	return 0;
}