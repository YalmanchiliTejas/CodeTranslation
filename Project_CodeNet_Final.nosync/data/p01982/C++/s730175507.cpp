#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,l,r;
	//while(scanf("%d%d%d",&n,&l,&r),n){
	cin>>n>>l>>r;
	while(n!=0){
	int A[1000];
	//scanf("%d%d%d",&A[0],&A[1],&A[2]);
	for(int i=0;i<n;i++) cin>>A[i];
	int Unum=0;
	for(int i=l;i<=r;i++){
		int count=0;
		for(int k=0;k<n;k++){
			if(i%A[k]==0){
				count++;
				if(k%2==0){
					Unum++;
				}
				break;
			}
		}
		if(count==0&&n%2==0){
				Unum++;
			}
	}
	//printf("%d\n",Unum);
	cout<<Unum<<endl;
	cin>>n>>l>>r;
	}

	return 0;
}

