n = int(input())
h = list(map(int, input().split()))
hmax = 0
ans = 0
for i in range(n):
    if h[i] >= hmax:
        ans += 1
        hmax = h[i]
print(ans)
