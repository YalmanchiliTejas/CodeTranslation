#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin>>n;

    vector<int> A(n);

    long int sum =0;

    for(int i=0;i<n;i++){
    	
    	cin>>A[i];

    	sum+=A[i];

    	sum%=MAX;

    }
    long long int ans =0;
    for(int i=0;i<n;i++){
    	sum-=A[i];
    	if(sum<0){
    		sum	+=MAX;
    	}
    	ans+=A[i]*sum;
		ans%=MAX;    	
    }
    cout<<ans<<endl;
}