#include<iostream>
#include<vector>
using namespace std;


int n;

pair<long long, long long> caldiff(vector<long long> & elements,  vector<vector<pair<long long, long long>>> &dp, 
                    int i, int j, bool player)
{
    //cout << "#1:  i " << i <<" j " << j << " player: " << player<< endl;
    if (dp[i][j].first != 0 || dp[i][j].second != 0) {
     
     //cout << "#2: i " << i <<" j " << j << " " << dp[i][j].first << "  " << dp[i][j].second <<endl;
     
      return dp[i][j];
    }

    if (i == j)
    {
        if (player == 1)
          dp[i][j] = make_pair(elements[i], 0);
        else
        {
          dp[i][j] = make_pair(0, elements[i]);
        }
       // cout << "#3:  i " << i <<" j " << j << " " << dp[i][j].first << "  " << dp[i][j].second <<endl;
        return dp[i][j];
    }
    pair <long long, long long> x = caldiff(elements, dp, i+1, j, (player+1)%2);
    pair <long long, long long> y = caldiff(elements, dp, i, j-1, (player+1)%2);

    if (player){
      if (elements[i] + x.first > elements[j] + y.first) {
      dp[i][j].first = elements[i] + x.first;
      dp[i][j].second = x.second;
      }
      else
      {
         dp[i][j].first = elements[j] + y.first;
         dp[i][j].second = y.second;
      }
    }
    else
    {
       if (elements[i] + x.second > elements[j] + y.second) {
      dp[i][j].second = elements[i] + x.second;
      dp[i][j].first = x.first;
      }
      else
      {
         dp[i][j].second = elements[j] + y.second;
         dp[i][j].first = y.first;
      }
    }
    //cout<< "#4: dp[i][j] " << dp[i][j].first << " " << dp[i][j].second<<endl; 

    return dp[i][j];
}
int main()
{
    scanf("%d", &n);
    vector<long long> elements(n);
    for(auto &x: elements)
      scanf("%lld", &x);
    vector<vector<pair<long long, long long> >> arr(3000);
    for (auto &x: arr)
      x = vector<pair<long long, long long> >(3000, make_pair(0,0));
    caldiff(elements, arr, 0, n-1, 1);
    cout << arr[0][n-1].first - arr[0][n-1].second <<endl;

    return 0;
}