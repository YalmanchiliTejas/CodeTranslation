#include<bits/stdc++.h>
using namespace std;

int dp[100][5][2];
vector<int> arr;

int check(int pos,int count,bool flag,int k,int sz){
    if(pos>=sz) return count==k?1:0;
    if(count > k) return 0;
    if(dp[pos][count][flag] != -1) return dp[pos][count][flag];
    
    int limit = 9;
    if(!flag) limit = arr[pos];
    
    int res = 0;
    for(int i=0;i<=limit;i++){
        if(flag || i<limit){
            if(i==0) res+= check(pos+1,count,true,k,sz);
            else res+= check(pos+1,count+1,true,k,sz);
        }
        else{
            if(i==0) res+= check(pos+1,count,false,k,sz);
            else res+= check(pos+1,count+1,false,k,sz);
        }
    }
    
    dp[pos][count][flag] = res;
    return res;
}

int main() {
	string s;
	int k;
	cin >> s;
	cin >> k;
	for(int i=0;i<100;i++)
	    for(int j=0;j<5;j++)
	        for(int k=0;k<2;k++)
	            dp[i][j][k] = -1;
	for(auto i:s){
	    arr.push_back(i-'0');
	}
	cout << check(0,0,false,k,s.size());
	return 0;
}