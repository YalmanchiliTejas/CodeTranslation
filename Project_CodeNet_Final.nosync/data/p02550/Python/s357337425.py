n, x, m = map(int, input().split())

dp = [-1 for _i in range(10**5+2)]
nums = [-1 for _i in range(10**5+2)]
nums[x] = 1

dp[x] = x
bef = x
nex = (x**2)%m
r = [0, x]
while dp[nex] < 0:
    nums[nex] = nums[bef]+1
    dp[nex] = dp[bef]+nex
    r.append(dp[nex])
    nex, bef = (nex**2)%m, nex

if nex == 0:
    print(r[min(len(r)-1, n)])
elif n <= nums[bef]:
    print(r[n])
else:
    roop = nums[bef] - nums[nex] + 1
    roop_value = r[nums[bef]] - r[nums[nex] - 1]
    plus = r[nums[nex]-1]*(n>=nums[nex]+1)
    n = max(0, n-nums[nex]+1)
    print(
        roop_value*(n//roop)+plus+
        r[n%roop + nums[nex] -1]
        -r[nums[nex] - 1]
    )