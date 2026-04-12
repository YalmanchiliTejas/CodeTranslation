#include<iostream>
#define ll long long



using namespace std;

ll dp[3001][3001] ={0};

ll P1(ll arr[],int i, int j)
{
  if(i>j)
    return 0;

  if(dp[i][j] != 0)
    return dp[i][j];

  ll op1 = arr[i] + min( /*arr[i+1] +*/ P1(arr,i+2,j), /*arr[j] +*/ P1(arr,i+1,j-1));
  ll op2 = arr[j] + min(/*arr[i] +*/ P1(arr,i+1,j-1), /*arr[j-1] +*/ P1(arr,i,j-2));

  return dp[i][j] = max(op1,op2);
}

int main()
{
  int n;
  cin>>n;
  ll arr[n];

  ll total_score = 0;

  for(int i = 0 ; i<n ; i++)
  {
    cin>>arr[i];
    total_score += arr[i];
  }

  ll final_X = P1(arr,0,n-1);
  ll final_Y = total_score - final_X;

  cout<<final_X - final_Y;
  
  return 0;
}