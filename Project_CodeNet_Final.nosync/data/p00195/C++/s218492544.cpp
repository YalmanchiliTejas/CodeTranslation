#include<bits/stdc++.h>
using namespace std;
int A[5],B[5];
string S;
int main()
{
	S="ABCDE";
	while(true){
		scanf("%d%d",&A[0],&B[0]);
		if(A[0]==0&&B[0]==0)return 0;
		for(int i=1;i<5;i++){
			scanf("%d%d",&A[i],&B[i]);
		}
		int ma=-1;int maxi=-1;
		for(int i=0;i<5;i++){
			if(ma<A[i]+B[i]){
				ma=A[i]+B[i];
				maxi=i;
			}
		}
		cout << S[maxi] << " " << ma << "\n";
	}
}