a, b, c, x, y = map(int, input().split())


ans = float("INF")
for i in range(10**5 + 1):
    val = 2*c*i + a*max(x-i, 0) + b*max(y-i, 0)
    ans = min(ans, val)


print(ans)