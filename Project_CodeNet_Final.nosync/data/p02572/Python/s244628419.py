N = int(input())
A = list(map(int, input().split()))

s = sum(A)
ans = 0
for a in A:
    s -= a
    ans += a * s
    ans %= 10**9 + 7

print(ans)