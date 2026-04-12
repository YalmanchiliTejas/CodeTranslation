n = int(input())
h = list(map(int, input().split()))
m = [0] * n
m[0] = h[0]
for i in range(n - 1):
    m[i + 1] = max(m[i], h[i + 1])
ans = 0
for hi, mi in zip(h, m):
    if hi == mi:
        ans += 1
print(ans)