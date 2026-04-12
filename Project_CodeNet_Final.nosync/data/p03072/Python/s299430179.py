n = int(input())
h = list(map(int, input().split()))
ans = 1
maxH = h[0]

for i in range(1, n):
    if h[i] >= maxH:
        ans += 1
        maxH = h[i]

print(ans)
