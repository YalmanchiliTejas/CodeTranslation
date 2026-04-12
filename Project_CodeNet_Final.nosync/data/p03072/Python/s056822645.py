n = int(input())
h = list(map(int, input().split()))
ans = 1
m = 0

for i in range(1, n, 1):
    m = max(m, h[i - 1])
    if (m <= h[i]):
        ans += 1

print(ans)
