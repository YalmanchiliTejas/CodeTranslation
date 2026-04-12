#include<iostream>
#include<bits/stdc++.h>

#define fl(k, n) for(int i = k; i < n; i++)
#define flr(k, n) for(int i = n - 1; i >= k; i--)
#define vi vector<int>
#define vp vector<pair<int, int>>
#define mp make_pair
#define ll long long
#define llu long long unsigned int
#define mod 1000000007

using namespace std;

int binary_search(vector<int> nums, int target_val){
  int begin = 0;
  int end = nums.size();
  int mid;

  while(begin <= end){
    mid = begin + (end - begin) / 2;
    if(nums[mid] == target_val)
      return mid;
    else if(nums[mid] <= target_val && nums[mid + 1] > target_val)
      return mid;
    else if(nums[mid] > target_val)
      end = mid - 1;
    else
      begin = mid + 1;
  }

  if(begin == 0)
    return -1;
  else 
    return nums.size();
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<ll> nums(n);
  fl(0, n)
    cin >> nums[i];

  vector<vector<ll>> max_diff(n, vector<ll>(n));

  for(int l = n - 1; l >= 0; l--){
    for(int r = l; r < n; r++){
      if(l == r)
        max_diff[l][r] = nums[l];
      else{
        max_diff[l][r] = max(nums[l] - max_diff[l + 1][r], nums[r] - max_diff[l][r - 1]);
      }
    }
  }

  cout << max_diff[0][n - 1] << "\n";

}