n = int(input())
*h, = map(int, input().split())


hm = h[0]
ans = 1
for i in range(1, n):
    if h[0] <= h[i] and hm <= h[i]:
        ans += 1
        hm = max(hm, h[i])

print(ans)
