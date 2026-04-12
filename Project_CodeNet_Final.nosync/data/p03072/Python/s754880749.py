n = int(input())
h = list(map(int, input().split()))
ans = 1
maxHigh = h[0]
for i in range(1,n):
    if maxHigh <= h[i]:
        maxHigh = h[i]
        ans += 1
print(ans)