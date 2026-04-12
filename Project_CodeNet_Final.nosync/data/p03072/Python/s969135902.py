n = int(input())
h = list(map(int, input().split()))

ans = 0
h_max = 0
for i in range(n):
    if h_max <= h[i]:
        ans += 1
        h_max = h[i]

print(ans)
