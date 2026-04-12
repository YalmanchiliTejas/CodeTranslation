#include "math.h"
#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N,K;
	string S,ans;

    cin>>N;
    cin>>S;
    cin>>K;
	
	ans=S;

	for(int i=0;i<N;i++){
		if(S[K-1] != S[i]){
			ans[i] = '*';
		}
	}
    
    cout<<ans<<endl;
    return 0;

}