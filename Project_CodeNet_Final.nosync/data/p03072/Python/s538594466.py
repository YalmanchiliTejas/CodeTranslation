n = int(input())
h = list(map(int, input().split()))
ans = 0
k = 0
for i in range(n):
    if h[i] >= k:
        ans += 1
    k = max(k, h[i])
print(ans)