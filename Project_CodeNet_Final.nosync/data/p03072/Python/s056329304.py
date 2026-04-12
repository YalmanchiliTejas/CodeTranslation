n = int(input())
h = list(map(int,input().split()))
ans = 0
ma = h[0]
for i in range(n):
    if ma <= h[i]:
        ans += 1
        ma = h[i]
print(ans)