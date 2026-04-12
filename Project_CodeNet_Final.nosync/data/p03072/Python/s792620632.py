n = int(input())
h = list(map(int, input().split()))
maxheight = 0
ans = 0
for i in range(n):
    if maxheight <= h[i]:
        ans += 1
        maxheight = max(h[i], maxheight)
print(ans)
