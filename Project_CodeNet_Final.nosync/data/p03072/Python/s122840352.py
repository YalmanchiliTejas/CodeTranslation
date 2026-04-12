n = int(input())
h = list(map(int, input().split()))

h_max = 0
ans = 0
for i in range(n):
    if h[i] >= h_max:
        ans += 1
        h_max = h[i]
print(ans)
