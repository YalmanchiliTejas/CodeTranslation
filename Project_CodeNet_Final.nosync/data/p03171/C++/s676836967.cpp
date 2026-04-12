/***********************************
*******AUTHOR SHASHI KANT **********         
****GMAIL Shshiksnt140895@gmail.com*
************************************                                  
***********************************/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*class graph
{
	map<int,list<int>>adj;
	public :
	       void addedge(int a, int b)
	       {
	           adj[a].push_back(b);
	           adj[b].push_back(a);
	       }

}*/
	ll dp[3001][3001];
ll max_value(int arr[], int i, int j, int turn)
{

       //cout<< "hello" <<" ";
        if(i>j)
        	return 0;

        if(dp[i][j] != -1)
        	return dp[i][j];

       if(turn == 1)
       	return  dp[i][j] =  max(arr[i]+max_value(arr, i+1, j, 0), arr[j]+max_value(arr, i, j-1, 0));
       else
       	 return dp[i][j] = min(max_value(arr,i+1, j , 1), max_value(arr,i, j-1, 1 ));
}
int main(){
       int n;
       cin>>n;
       int arr[n];
       ll sum =0;
               memset(dp, -1, sizeof(dp));
       for(int i=0; i<n; i++)
       {
           cin>>arr[i];
           sum+=arr[i];
       }

       ll max1  = max_value(arr, 0, n-1,1) ;
      // cout<< max1 <<" ";
       ll max2 = sum - max1;
       cout<< max1 - max2 <<endl;

	return 0;
}