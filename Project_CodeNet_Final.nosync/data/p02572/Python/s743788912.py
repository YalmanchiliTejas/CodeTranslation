N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7

s = sum(A)
ans = 0
for i, a in enumerate(A):
    s -= a
    ans = (ans + s * a) % mod

print(ans)