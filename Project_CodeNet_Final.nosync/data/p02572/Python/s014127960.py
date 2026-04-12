import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")

n = int(input())
a = [int(x) for x in input().split()]

total = sum(a)
mod = 10**9 + 7

ans = 0

for i in range(n):
    total -= a[i]
    ans += a[i] * total
    ans %= mod

print(ans)