#include <bits/stdc++.h> 
using namespace std; 
const int M=105; 
int dp[105][105][5]; 
int K,n1; 
int ct(int p, int c, int t, vector<int> num) 
{ 
    if (p==num.size()) 
	{ 
        if (c==K) return 1; 
        return 0; 
	}
    if (dp[p][c][t]!=-1) 
    	return dp[p][c][t]; 
    int ans=0; 
    int l=(t?9:num[p]); 
    for (int i=0; i<=l; i++) 
	{ 
        int currCnt =c; 
        if (i!=0)  currCnt++; 
        int currTight=t; 
        if (i<num[p]) 
            currTight=1; 
        ans+=ct(p+1, currCnt, currTight, num); 
    } 
    return dp[p][c][t]=ans; 
} 
int countInRange(string x) 
{ 
	n1=x.size();
    vector<int> num; 
    while (n1>0) 
	{
		n1--;
        num.push_back(int(x[n1]-'0')); 
    } 
    reverse(num.begin(), num.end()); 
    memset(dp, -1, sizeof(dp)); 
    return ct(0, 0, 0, num); 
} 
int main() 
{ 
    string R;
	cin>>R; 
    cin>>K;
    cout<<countInRange(R)<<endl; 
} 