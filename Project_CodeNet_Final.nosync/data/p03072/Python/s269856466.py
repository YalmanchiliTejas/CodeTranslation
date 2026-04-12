n = int(input())
h = list(map(int, input().split()))
maxi = 0
ans = 0
for i in range(n):
    if h[i] >= maxi: ans += 1
    maxi = max(maxi, h[i])
print(ans)