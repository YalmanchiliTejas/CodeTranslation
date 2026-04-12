n = int(input())
h = list(map(int,input().split()))

x = 0
ans = 0
for i in range(n):
    if x <= h[i]:
        ans += 1
        x = max(x,h[i])
print(ans)