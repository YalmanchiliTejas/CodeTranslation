#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cassert>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;


int n,s[200];

/*
input data
*/

void init(){
}

bool input(){
	cin>>n;
	if(n==0) return false;
	for(int i=0; i<n; i++) cin>>s[i];
	return true;
}


void swap(){
	int tmp;
	for(int i=0; i<n; i++){
		for(int j=n-1; j>i; j--){
			if(s[j-1]>s[j]){
				tmp=s[j-1];
				s[j-1]=s[j];
				s[j]=tmp;
			}
		}
	}
}



int solve(){
	int sum=0, ans=0;
	swap();
	for(int i=1; i<n-1; i++){
		sum+=s[i];
	}
	ans=sum/(n-2);
	return ans;
}


int main(){
  while(input()){
    cout<<solve()<<endl;
  }
}