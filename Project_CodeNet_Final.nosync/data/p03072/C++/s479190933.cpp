#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;cin>>N;
	int H[N];int temp=0,count=0;
	for(int i=0;i<N;i++){
		cin>>H[i];
		if(H[i]>=temp){
			count++;
			temp=H[i];
		}
	}cout<<count<<endl;
}