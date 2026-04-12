n = int(input())
nums = list(map(int,input().split()))
if n == 2:
    print(max(nums[0],nums[1]))
else:
    temp =[0]
    for i in range(n):
        if i%2 == 0:
            temp += [temp[-1]+nums[i]]
    dp = [[0,0,0] for _ in range(n)]
    dp[0][0] = nums[0]
    dp[1][0],dp[1][1],dp[1][2] = nums[1],nums[0],-float("inf")
    dp[2][0],dp[2][1],dp[2][2] = nums[2],nums[1],nums[0]
    for i in range(3,n):
        if i%2 == 0:
            dp[i][0] = max(dp[i-2]) + nums[i]
            dp[i][1] = max(dp[i-3]) + nums[i-1]
            dp[i][2] = temp[i//2]
        else:
            dp[i][0] = max(dp[i-2]) + nums[i]
            dp[i][1] = temp[(i-1)//2] + nums[i-1]
            dp[i][2] = -float("inf")
    print(max(dp[n-1]))