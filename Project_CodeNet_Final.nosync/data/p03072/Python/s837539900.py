n = int(input())
h = list(map(int,input().split()))
v = h[0]
ans = 0
for i in range(n):
    if v <= h[i]:
        v = h[i]
        ans += 1
print(ans)