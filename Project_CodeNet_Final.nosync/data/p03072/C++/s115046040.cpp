#include<bits/stdc++.h>
using namespace std;

int H[25],n;
int sum=0;

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>H[i];
	for(int i=0;i<n;i++){
		bool f=true;
		for(int j=0;j<i;j++)
			if(H[j]>H[i]) f=false;
		if(f) sum++;
	}
	cout<<sum<<endl;
	return 0;
}