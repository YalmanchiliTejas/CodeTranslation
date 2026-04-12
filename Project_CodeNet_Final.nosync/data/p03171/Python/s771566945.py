n = int(input())
nums = list(map(int, input().split()))
dp = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
  dp[i][i] = nums[i]
  
for k in range(2, n+1):
  for l in range(n-k+1):
    r = l+k-1
    dp[l][r] = max(nums[l]-dp[l+1][r], nums[r] - dp[l][r-1])
    
print(dp[0][-1])