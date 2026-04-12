mod = 10 ** 9 + 7
n = int(input())
a = list(map(int, input().split()))
dp = [0]

def calc(A, n, dp):
    dp += [A[0] * A[1]]
    rsum = A[0] + A[1]
    for i in range(2, n):
        dp += [dp[-1] + rsum * A[i]]
        rsum += A[i]

    i = dp.index(max(dp))
    rsum = 0
    for j in range(i + 1):
        rsum += A[j]
    res = max(dp)
    dp2 = max(dp)
    for j in range(0, i):
        rsum -= A[j]
        dp2 -= A[j] * rsum
        res = max(dp2, res)
    return res

ans = calc(a, n, dp) % mod
print(ans)

