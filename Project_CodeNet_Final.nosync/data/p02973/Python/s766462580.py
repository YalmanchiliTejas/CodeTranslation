from bisect import bisect_right

N, *A = map(int, open(0).read().split())

A.reverse()

dp = [A[0]]
for a in A[1:]:
    if dp[-1] <= a:
        dp.append(a)
    else:
        dp[bisect_right(dp, a)] = a

print(len(dp))
