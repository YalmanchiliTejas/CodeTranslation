n = int(input())
h = list(map(int,input().split()))
m = 0
ans = 0
for i in range(n):
    if m<=h[i]:
        m = h[i]
        ans += 1
print(ans)