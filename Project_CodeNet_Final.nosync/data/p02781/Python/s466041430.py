from collections import defaultdict as dd
N = int(input())
K = int(input())

s = str(N)

dp = dd(int)
dp[(True, 1)] = 1
dp[(False, 1)] = int(s[0])-1
dp[(False, 0)] = 1

for c in s[1:]:
    i = int(c)
    ndp = {}
    if i != 0:
        ndp[(True, 0)] = 0
        ndp[(True, 1)] = dp[(True, 0)]
        ndp[(True, 2)] = dp[(True, 1)]
        ndp[(True, 3)] = dp[(True, 2)]
        ndp[(False, 0)] = dp[(False, 0)] + dp[(True, 0)]
        ndp[(False, 1)] = dp[(False, 1)] + dp[(False, 0)]*9 + dp[(True, 0)]*(i-1) + dp[(True, 1)]
        ndp[(False, 2)] = dp[(False, 2)] + dp[(False, 1)]*9 + dp[(True, 1)]*(i-1) + dp[(True, 2)]
        ndp[(False, 3)] = dp[(False, 3)] + dp[(False, 2)]*9 + dp[(True, 2)]*(i-1) + dp[(True, 3)]
    else:
        ndp[(True, 0)] = dp[(True, 0)]
        ndp[(True, 1)] = dp[(True, 1)]
        ndp[(True, 2)] = dp[(True, 2)]
        ndp[(True, 3)] = dp[(True, 3)]
        ndp[(False, 0)] = dp[(False, 0)]
        ndp[(False, 1)] = dp[(False, 1)] + dp[(False, 0)]*9
        ndp[(False, 2)] = dp[(False, 2)] + dp[(False, 1)]*9
        ndp[(False, 3)] = dp[(False, 3)] + dp[(False, 2)]*9
    dp = ndp
print(dp[True, K] + dp[False, K])