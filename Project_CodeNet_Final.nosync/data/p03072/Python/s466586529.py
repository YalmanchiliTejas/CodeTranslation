n = int(input())
h = list(map(int, input().split()))
max_h = h[0]
ans = 1
for i in range(n-1):
    if h[i+1] >= max_h:
        ans += 1
        max_h = h[i+1]
print(ans)
