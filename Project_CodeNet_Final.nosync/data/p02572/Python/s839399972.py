N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7

cur = sum(A)
ans = 0
for ai in A:
    cur -= ai
    ans += ((cur % mod) * ai) % mod
    ans %= mod

print(ans)