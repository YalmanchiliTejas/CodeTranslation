n = int(input())
h = list(map(int, input().split()))

ans = 1
m = h[0]
for i in range(1, n):
    m = max(h[i-1], m)
    if h[i] >= m:
        ans += 1

print(ans)
