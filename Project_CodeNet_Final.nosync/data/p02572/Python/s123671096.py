n = int(input())
A = list(map(int, input().split()))
ans = 0
mod = 10**9 + 7

s = sum(A)

for a in A:
    s -= a
    ans += a * s

print(ans%mod)