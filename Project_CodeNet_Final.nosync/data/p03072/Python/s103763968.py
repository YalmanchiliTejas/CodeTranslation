n = int(input())
h = list(map(int, input().split()))
maxHigh = 0
ans = 0
for i in range(n):
    if maxHigh <= h[i]:
        maxHigh = h[i]
        ans+=1
print(ans)