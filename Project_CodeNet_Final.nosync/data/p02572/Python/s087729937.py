from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))

cumsum = [0] + list(accumulate(a))
sum_a = cumsum[-1]
mod = 10**9 + 7
res = 0
for i in range(n):
    res += a[i] * (sum_a - cumsum[i+1])
    res %= mod
print(res)
