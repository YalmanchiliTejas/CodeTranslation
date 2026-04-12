#include<iostream>
using namespace std;
typedef pair<int,int> p;
p P(int a,int b){
	p PP;
	PP.first=a; PP.second=b;
	return PP;
}

int main(){
while(1){
	p A[100000+2];
	int n,k=0,in,ans=0;
	scanf("%d",&n);
	if(n==0)break;
	for(int i=0;i<n;i++){
		scanf("%d",&in);
		if(i%2==0){
			if(k==0){A[0]=P(in,1); k++;}
			else {
				if(in==A[k-1].first)A[k-1].second++;
				else {A[k]=P(in,1); k++;}
			}
		}
		else {
			if(in==A[k-1].first)A[k-1].second++;
			else{
				if(k==1){A[0]=P((A[0].first+1)%2,A[0].second+1);}
				else {
					A[k-2].second+=A[k-1].second+1;
					k--;
				}
			}
		}
	}
	for(int i=0;i<k;i++){
		if(A[i].first==0)ans+=A[i].second;
	}
	printf("%d\n",ans);
}
}