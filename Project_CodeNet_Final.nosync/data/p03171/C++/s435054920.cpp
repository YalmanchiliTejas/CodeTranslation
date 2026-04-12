// OPTIMAL GAME STRATEGY-I
// Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes it from the row. The value of coin is received by that player. Determine the maximum value that piyush can win if he moves first. Both the players play optimally.


// Input Format:
// First line contains the number of coins 'n'. Second line contains n space separated integers which is the value of ith coin.

// Constraints:
// N < 30

// Output Format:
// Print a single line with the maximum possible value.

// Sample Input:
// 4
// 1 2 3 4
// Sample Output:
// 6
// Explanation:
// Piyush will pick the coin 4. Then nimit can pick either 1 or 3. In both the cases piyush picks coin 2 and wins with a total of 6.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3001][3001];
ll GETSCORE(ll array[],ll startingIndex,ll endingIndex)
{
    if(endingIndex<startingIndex)
    {
        return 0;
    }
    if(dp[startingIndex][endingIndex]!=-1)
    {
        return dp[startingIndex][endingIndex];
    }
    ll score=0;
   
    ll start=array[startingIndex]+min(GETSCORE(array,startingIndex+1,endingIndex-1),GETSCORE(array,startingIndex+2,endingIndex));
    ll end=array[endingIndex]+min(GETSCORE(array,startingIndex+1,endingIndex-1),GETSCORE(array,startingIndex,endingIndex-2));
    score+=max(start,end);
    dp[startingIndex][endingIndex]=score;
    return score;
    
}
int main()
{
    ll N;
   
    cin>>N;
     ll array[N];
     ll sum=0;
    for(ll p=0;p<N;p++)
    {
        cin>>array[p];
        sum+=array[p];
    }
    memset(dp,-1,sizeof(dp));
  
     ll count= GETSCORE(array,0,N-1);
     ll ScoreY=sum-count;
    cout<<count-ScoreY<<endl;
	
}