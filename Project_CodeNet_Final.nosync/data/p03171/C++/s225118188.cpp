#include <bits/stdc++.h>
#define endl "\n"
#include <set>


using namespace std;
int main(){
    
ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
int n;
cin>>n;
vector <int> a;
for (int i=0; i<n; i++)
{
	int temp; cin>>temp;
	a.push_back(temp);
}

long long int dp[n][n];
for (int i=0; i<n; i++)
{
	dp[i][i]=a[i];
}

for (int diff=1; diff<n; diff++)
{
	for (int i=0; i<n && i+diff<n; i++)
	{
		int j=i+diff;
		dp[i][j]= max(-dp[i+1][j] + a[i], -dp[i][j-1]+ a[j]);
	}
}

cout<<dp[0][n-1]<<endl;
}