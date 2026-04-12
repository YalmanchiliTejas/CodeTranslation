from itertools import accumulate
n = int(input())
a = list(map(int, input().split()))
MOD = 10**9+7
ac = list(accumulate(a))

ans = 0
for i in range(n-1):
    ans += (ac[i]*a[i+1])
    ans %= MOD
print(ans)