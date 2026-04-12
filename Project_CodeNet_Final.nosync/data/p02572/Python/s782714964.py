N = int(input())
A = list(map(int, input().split()))

M = 10**9+7

entire = sum(A) % M

ans = 0
s = 0
for a in A:
    entire -= a
    entire %= M
    ans += (a*entire)%M
    ans %= M
print(ans)
