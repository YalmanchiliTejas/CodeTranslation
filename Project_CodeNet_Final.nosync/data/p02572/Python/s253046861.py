from itertools import accumulate
n = int(input())
*a, = map(int, input().split())
cumsum = [0] + list(accumulate(a))
ans = sum(a[i]*cumsum[i] for i in range(n))
mod = 10**9 + 7
print(ans % mod)