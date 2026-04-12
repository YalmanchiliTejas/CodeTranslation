# Problem E - Almost Everywhere Zero

# input
N = list(input())
N = list(map(int, N))
K = int(input())

# initialization
dp = [[[0]*4 for i in range(2)] for j in range(len(N)+1)] # dp[keta][smaller][nums]
dp[0][0][0] = 1

# dp
for keta in range(len(N)): # keta loop
    for smaller in range(2): # smaller loop
        limit = 0
        if smaller==0:
            limit = N[keta]
        else:
            limit = 9
        for n in range(limit + 1):
            # not 0 update
            if n==0:
                for x in range(4):
                    dp[keta+1][smaller or n<limit][x] += dp[keta][smaller][x]
            else:
                for x in range(2, -1, -1):
                    dp[keta+1][smaller or n<limit][x+1] += dp[keta][smaller][x]

# output
ans = dp[len(N)][0][K] + dp[len(N)][1][K]
print(ans)
