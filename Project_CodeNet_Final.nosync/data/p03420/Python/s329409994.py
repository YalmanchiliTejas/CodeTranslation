n, k = map(int, input().split())
ans = 0

for i in range(1, n + 1):
    ans += max((n//i)*(i - k), 0) + max((n%i - k + 1), 0)

if k == 0:
    ans = n**2

print(ans)