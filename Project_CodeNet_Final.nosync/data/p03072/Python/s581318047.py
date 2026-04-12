n = int(input())
h = list(map(int, input().split()))
m = 0
ans = 0
for i in range(n):
    if h[i] >= m:
        m = h[i]
        ans += 1
print(ans)
