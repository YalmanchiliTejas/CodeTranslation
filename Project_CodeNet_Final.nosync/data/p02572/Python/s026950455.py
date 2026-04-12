from itertools import accumulate
n = int(input())
a = [int(i) for i in input().split()]
mod = 10 ** 9 + 7
a_acc = list(accumulate(a))
ans = 0
for i in range(n):
    ans += (a[i] * (a_acc[-1] - a_acc[i])) % mod
    ans %= mod
print(ans)