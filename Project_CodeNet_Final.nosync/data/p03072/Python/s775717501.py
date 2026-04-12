n = int(input())
h = list(map(int, input().split()))
ans = 1
highest = h[0]
for i in range(1, n):
    if h[i] >= highest:
        ans += 1
        highest = h[i]
print(ans)
