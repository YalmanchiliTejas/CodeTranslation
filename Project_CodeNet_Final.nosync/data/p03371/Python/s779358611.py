a, b, c, x, y = list(map(int, input().split()))
INF = float("inf")
ans = INF
for ab in range(max(x, y)*2+1):
    if ab % 2 == 0:
        ans = min(ans, ab*c + max(x-ab//2, 0)*a + max(y-ab//2, 0)*b)
print(ans)
