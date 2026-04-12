N = int(input())
A = [int(input()) for _ in range(N)]
_A = [-a for a in A]

def LIS(seq):
    import bisect
    dp = [seq[0]]
    for s in seq[1:]:
        if s >= dp[-1]:
            dp.append(s)
        else:
            dp[bisect.bisect_right(dp,s)] = s
    return len(dp)
assert(LIS([2,2,1,4,1,5,1,1,1])==5)

print(LIS(_A))
    